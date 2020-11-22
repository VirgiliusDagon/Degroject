using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Win32;

namespace Backuper
{
    public static class Preferences
    {
        public static string GetFromPreference()
        {
            RegistryKey backuper = GetBackuperKey(false);

            return backuper?.GetValue("fromPath")?.ToString();
        }

        public static string GetToPreference()
        {
            RegistryKey backuper = GetBackuperKey(false);

            return backuper?.GetValue("toPath")?.ToString();
        }

        public static void SetFromPreference(string fromPath)
        {
            if (fromPath == null)
                return;

            RegistryKey backuper = GetBackuperKey(true);
            if (backuper == null)
                backuper = CreateBackuperKey();

            backuper.SetValue("fromPath", fromPath);
        }

        public static void SetToPreference(string toPath)
        {
            if (toPath == null)
                return;

            RegistryKey backuper = GetBackuperKey(true);
            if (backuper == null)
                backuper = CreateBackuperKey();

            backuper.SetValue("toPath", toPath);
        }

        private static RegistryKey GetBackuperKey(bool writable)
        {
            return Registry.CurrentUser.OpenSubKey("Software").OpenSubKey("Backuper", writable);
        }

        private static RegistryKey CreateBackuperKey()
        {
            return Registry.CurrentUser.OpenSubKey("Software", true).CreateSubKey("Backuper");
        }
    }
}
