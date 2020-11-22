using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Backuper
{
    public partial class Form1 : Form
    {
        private string fromPath;
        private string toPath;


        public Form1()
        {
            InitializeComponent();
            fromPath = Preferences.GetFromPreference();
            toPath = Preferences.GetToPreference();
            textBox1.Text = fromPath;
            textBox2.Text = toPath;
        }

        private void fromButton_Click(object sender, EventArgs e)
        {
            using (FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog())
            {
                if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
                {
                    fromPath = folderBrowserDialog.SelectedPath;
                    textBox1.Text = fromPath;
                }
            }
        }

        private void toButton_Click(object sender, EventArgs e)
        {
            using (FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog())
            {
                if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
                {
                    toPath = folderBrowserDialog.SelectedPath;
                    textBox2.Text = toPath;
                }
            }
        }

        private void makeButton_Click(object sender, EventArgs e)
        {
            OverrideCopy(fromPath, toPath);
        }

        private void loadButton_Click(object sender, EventArgs e)
        {
            OverrideCopy(toPath, fromPath);
        }

        private void OverrideCopy(string originPath, string destinationPath)
        {
            if (originPath != null && destinationPath != null)
            {
                // Check if destination directory is not empty
                string[] destFiles = Directory.GetFiles(destinationPath);
                string[] destDirectories = Directory.GetDirectories(destinationPath);
                if (destFiles.Length > 0 || destDirectories.Length > 0)
                {
                    if (MessageBox.Show("Directory contains files and they will be deleted!\nContinue?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
                    {
                        foreach (string dir in destDirectories)
                        {
                            Directory.Delete(dir, true);
                        }
                        foreach (string file in destFiles)
                        {
                            File.Delete(file);
                        }
                    }
                    else
                    {
                        return;
                    }
                }


                string newPath;
                string[] filePaths = Directory.GetFiles(originPath, "*", SearchOption.AllDirectories);
                string[] directoryPaths = Directory.GetDirectories(originPath, "*", SearchOption.AllDirectories);
                // Copy all directories
                foreach (string directory in directoryPaths)
                {
                    newPath = directory.Replace(originPath, destinationPath);
                    Directory.CreateDirectory(newPath);
                }
                // Copy all files
                foreach (string file in filePaths)
                {
                    newPath = file.Replace(originPath, destinationPath);
                    File.Copy(file, newPath);
                }
            }
            else
            {
                MessageBox.Show("Invalid directory path", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Preferences.SetFromPreference(fromPath);
            Preferences.SetToPreference(toPath);
        }
    }
}
