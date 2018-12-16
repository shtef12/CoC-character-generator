namespace COC_character_generator.Forms
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.CreateCharacterButton = new System.Windows.Forms.Button();
            this.QuitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // CreateCharacterButton
            // 
            this.CreateCharacterButton.Location = new System.Drawing.Point(307, 83);
            this.CreateCharacterButton.Name = "CreateCharacterButton";
            this.CreateCharacterButton.Size = new System.Drawing.Size(137, 48);
            this.CreateCharacterButton.TabIndex = 0;
            this.CreateCharacterButton.Text = "Create Character";
            this.CreateCharacterButton.UseVisualStyleBackColor = true;
            // 
            // QuitButton
            // 
            this.QuitButton.Location = new System.Drawing.Point(307, 173);
            this.QuitButton.Name = "QuitButton";
            this.QuitButton.Size = new System.Drawing.Size(137, 48);
            this.QuitButton.TabIndex = 1;
            this.QuitButton.Text = "Quit";
            this.QuitButton.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.QuitButton);
            this.Controls.Add(this.CreateCharacterButton);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button CreateCharacterButton;
        private System.Windows.Forms.Button QuitButton;
    }
}