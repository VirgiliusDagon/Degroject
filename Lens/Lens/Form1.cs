using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lens
{
    public partial class Lens : Form
    {
        float d = 0.1f;
        float D = 20f;
        float f;
        float F;
        float G;


        public Lens()
        {
            InitializeComponent();
            Recalculate();
        }

        void Recalculate()
        {
            f = 1f / (D - 1f / d);
            F = 1f / D;
            G = -f / d;
        }

        void RefreshInfo()
        {
            Recalculate();
            textBox3.Text = F.ToString();
            textBox4.Text = f.ToString();
            textBox5.Text = G.ToString();
            pictureBox1.Refresh();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Pen pen = new Pen(Color.Blue);

            float middle = pictureBox1.Height / 2;
            float width = pictureBox1.Width;
            const float arrowHeight = 70;
            const float lensHeight = 150;
            float arrowDist = d * 1000;
            float falseArrowDist = f * 1000;
            float falseArrowHeight = arrowHeight * G;

            // Draw blue axis
            g.DrawLine(pen, 0, middle, width, middle);
            // Draw Lines 
            pen.Color = Color.Yellow;
            g.DrawLine(pen, width / 2 - arrowDist, middle - arrowHeight, width, (width / 2 + arrowDist) / (-arrowDist) * (-arrowHeight) - arrowHeight + middle);
            g.DrawLine(pen, width / 2 - arrowDist, middle - arrowHeight, width / 2, middle - arrowHeight);
            g.DrawLine(pen, width / 2, middle - arrowHeight, width, (width / 2) / (F * 1000) * (arrowHeight) - arrowHeight + middle);

            // Draw false lines
            if (f < 0)
            {
                pen.Color = Color.Cyan;
                g.DrawLine(pen, width / 2, middle - arrowHeight, 0, (-width / 2) / (F * 1000) * (arrowHeight) - arrowHeight + middle);
                if (D > 0)
                    g.DrawLine(pen, width / 2 - arrowDist, middle - arrowHeight, 0, (-width / 2 + arrowDist) / (-arrowDist) * (-arrowHeight) - arrowHeight + middle);
            }

            // Draw false arrow
            if (width/2 - falseArrowDist > 0 && -width / 2 + falseArrowDist < 0)
            {
                pen.Color = Color.Green;
                pen.Width = 5;
                g.DrawLine(pen, width / 2 + falseArrowDist, middle, width / 2 + falseArrowDist, middle - falseArrowHeight);
            }

            // Draw lens
            pen.Color = Color.White;
            pen.Width = 1;

            float radius = 0.6f / D * 10000;
            float p1;
            float p2;
            if (radius < 0)
            {
                p1 = (radius + (float)Math.Sqrt(radius * radius - lensHeight * lensHeight)) / 4;
                p2 = (radius + (float)Math.Sqrt(radius * radius - lensHeight * lensHeight / 9)) / 4;
            }
            else
            {
                p1 = (radius - (float)Math.Sqrt(radius * radius - lensHeight * lensHeight)) / 4;
                p2 = (radius - (float)Math.Sqrt(radius * radius - lensHeight * lensHeight / 9)) / 4;
            }

            RectangleF originClip = g.ClipBounds;
            RectangleF lensClip = new RectangleF(0, middle - lensHeight, width, lensHeight * 2);
            Region region = new Region(lensClip);
            g.Clip = region;
            PointF[] points = {new PointF (width/2 - p1 + (D>0 ? +p1+2 :  2), middle - lensHeight),
                               new PointF (width/2 - p2 + (D>0 ? +p1+2 :  2), middle - lensHeight / 3),
                               new PointF (width/2 - p2 + (D>0 ? +p1+2 :  2), middle + lensHeight / 3),
                               new PointF (width/2 - p1 + (D>0 ? +p1+2 :  2), middle + lensHeight),
                               new PointF (width/2 + p1 + (D>0 ? -p1-2 : -2), middle + lensHeight),
                               new PointF (width/2 + p2 + (D>0 ? -p1-2 : -2), middle + lensHeight / 3),
                               new PointF (width/2 + p2 + (D>0 ? -p1-2 : -2), middle - lensHeight / 3),
                               new PointF (width/2 + p1 + (D>0 ? -p1-2 : -2), middle - lensHeight)};
            g.FillClosedCurve(pen.Brush, points);
            g.Clip = new Region(originClip);
            // Draw red arrow
            pen.Color = Color.Red;
            pen.Width = 5;
            g.DrawLine(pen, width / 2 - d * 1000, middle, width / 2 - d * 1000, middle - arrowHeight);
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            d = trackBar1.Value / 1000f;
            textBox1.Text = d.ToString();
            RefreshInfo();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            D = trackBar2.Value / 10f;
            textBox2.Text = (D).ToString();
            RefreshInfo();
        }
    }
}
