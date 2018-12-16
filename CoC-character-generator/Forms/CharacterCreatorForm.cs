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
    public partial class CharacterCreatorForm : Form
    {
        Character c = new Character();

        /// <summary>
        /// holds the updowns used to show/change characteristic values, the indices 
        /// should be in the same order as the CharacteristicNames enum.
        /// The last index is the move rate value
        /// </summary>
        List<NumericUpDown> characteristicUpDowns = new List<NumericUpDown>();

        /// <summary>
        /// List of all the textboxes for the character's skills
        /// </summary>
        List<TextBox> skillValues = new List<TextBox>();

        public CharacterCreatorForm()
        { 
            
            c.GenerateRandomCharacter();

            InitializeComponent();

            WindowState = FormWindowState.Maximized;

            NameTextEdit.Text = c.name;

            RandomCharacterButton.Click += new EventHandler(RandomCharacter_Click);

            //add characteristic spinner event handlers
            StrSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            DexSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            IntSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            ConSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            AppSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            EduSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            PowSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            SizeSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            MoveRateSpinner.ValueChanged += new EventHandler(CharacteristicSpinner_Click);
            
            //add characteristic spinners to the list
            characteristicUpDowns.Add(StrSpinner);
            characteristicUpDowns.Add(ConSpinner);
            characteristicUpDowns.Add(PowSpinner);
            characteristicUpDowns.Add(DexSpinner);
            characteristicUpDowns.Add(AppSpinner);
            characteristicUpDowns.Add(SizeSpinner);
            characteristicUpDowns.Add(IntSpinner);
            characteristicUpDowns.Add(EduSpinner);
            characteristicUpDowns.Add(MoveRateSpinner);

            NameTextEdit.TextChanged += new EventHandler(OnChangeName);
            PlayerTextEdit.TextChanged += new EventHandler(OnPlayerChange);
            tabPage1.TextChanged += new EventHandler(OnOccupationChange);
            AgeSpinner.ValueChanged += new EventHandler(AgeSpinner_Click);
            SexSpinner.SelectedItemChanged += new EventHandler(OnSexChanged);
            ResidenceTextEdit.TextChanged += new EventHandler(OnResidenceChanged);
            BirthplaceTextEdit.TextChanged += new EventHandler(OnBirthplaceChanged);
        }

        void RandomCharacter_Click(object sender, EventArgs e)
        {
            c.GenerateRandomCharacter();
            NameTextEdit.Text = c.name;
            OccupationTextEdit.Text = c.occupation;
        }

        void CharacteristicSpinner_Click(object sender, EventArgs e)
        {
            if (characteristicUpDowns.Contains(sender))
            {
                if (sender.Equals(MoveRateSpinner))
                {
                    c.movementRate = (int)MoveRateSpinner.Value;
                    System.Console.WriteLine(c.movementRate);
                }
                else
                {
                    int index = characteristicUpDowns.IndexOf((NumericUpDown)sender);
                    int value = (int)characteristicUpDowns[index].Value;
                    c.SetCharacteristicValue((CharacteristicName)index, value);
                    System.Console.WriteLine("new value: " + c.GetCharacteristicValue((CharacteristicName)index));
                }
            }
        }

        void AgeSpinner_Click(object sender, EventArgs e)
        {
            c.age = (int)AgeSpinner.Value;
        }

        void OnChangeName(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            c.name = textBox.Text;
        }

        void OnPlayerChange(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            c.player = textBox.Text;
        }

        void OnOccupationChange(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            c.occupation = textBox.Text;
        }

        void OnSexChanged(object sender, EventArgs e)
        {
            string sex = (string)SexSpinner.SelectedItem;
            if (sex == "Male")
                c.gender = true;
            else
                c.gender = false;
        }

        void OnResidenceChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            c.residence = textBox.Text;
        }

        void OnBirthplaceChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            c.birthplace = textBox.Text;
        }

        private void SkillsTableLayout_Paint(object sender, PaintEventArgs e)
        {

        }
    }

}
