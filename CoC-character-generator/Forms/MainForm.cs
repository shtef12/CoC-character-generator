using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COC_character_generator.Forms
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            WindowState = FormWindowState.Maximized;

            CreateCharacterButton.Click += new EventHandler(OpenCharacterCreatorForm);

            QuitButton.Click += new EventHandler(QuitProgram);
        }

        /// <summary>
        /// Open the character creator form and close this form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        private void OpenCharacterCreatorForm(object sender, EventArgs args)
        {
            Form characterCreatorForm = new CharacterCreatorForm();
            characterCreatorForm.Show();
            Close();
        }

        private void QuitProgram(object sender, EventArgs args)
        {
            Application.Exit();
        }
    }
}
