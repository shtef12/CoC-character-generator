#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "ui_mainwindow.h"
#include "character.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_firstNameEdit_returnPressed();

    void on_ageSpinBox_valueChanged(int arg1);

    void on_occupationEdit_returnPressed();

    void on_residenceEdit_returnPressed();

    void on_birthplaceEdit_returnPressed();

    void on_strSpinbox_valueChanged(int arg1);

    void on_dexSpinbox_valueChanged(int arg1);

    void on_intSpinbox_valueChanged(int arg1);

    void on_conSpinbox_valueChanged(int arg1);

    void on_appSpinbox_valueChanged(int arg1);

    void on_powSpinbox_valueChanged(int arg1);

    void on_sizSpinbox_valueChanged(int arg1);

    void on_eduSpinbox_valueChanged(int arg1);

    void on_hpSpinbox_valueChanged(int arg1);

    void on_sanitySpinbox_valueChanged(int arg1);

    void on_mpSpinbox_valueChanged(int arg1);

    void on_notesEdit_textChanged();

    void on_descEdit_textChanged();

    void on_beliefEdit_textChanged();

    void on_sigPplEdit_textChanged();

    void on_locEdit_textChanged();

    void on_possEdit_textChanged();

    void on_traitEdit_textChanged();

    void on_injEdit_textChanged();

    void on_fearEdit_textChanged();

    void on_gearEdit_textChanged();

    void on_spellEdit_textChanged();

    void on_encounterEdit_textChanged();

    void on_acctSpinner_valueChanged(int arg1);

    void on_anthroSpinner_valueChanged(int arg1);

    void on_appraiseSpinner_valueChanged(int arg1);

    void on_archaeologySpinner_valueChanged(int arg1);

    void on_artSpinner_valueChanged(int arg1);

    void on_charmSpinner_valueChanged(int arg1);

    void on_climbSpinner_valueChanged(int arg1);

    void on_creditRateSpinner_valueChanged(int arg1);

    void on_cthulhuMythosSpinner_valueChanged(int arg1);

    void on_disguiseSpinner_valueChanged(int arg1);

    void on_dodgeSpinner_valueChanged(int arg1);

    void on_driveSpinner_valueChanged(int arg1);

    void on_elecRepairSpinner_valueChanged(int arg1);

    void on_fastTalkSpinner_valueChanged(int arg1);

    void on_brawlSpinner_valueChanged(int arg1);

    void on_handgunSpinner_valueChanged(int arg1);

    void on_rifleSpinner_valueChanged(int arg1);

    void on_firstAidSpinner_valueChanged(int arg1);

    void on_historySpinner_valueChanged(int arg1);

    void on_intimidateSpinner_valueChanged(int arg1);

    void on_jumpSpinner_valueChanged(int arg1);

    void on_langOtherSpinner_valueChanged(int arg1);

    void on_langOwnSpinner_valueChanged(int arg1);

    void on_lawSpinner_valueChanged(int arg1);

    void on_librarySpinner_valueChanged(int arg1);

    void on_listenSpinner_valueChanged(int arg1);

    void on_lockSpinner_valueChanged(int arg1);

    void on_mRepairSpinner_valueChanged(int arg1);

    void on_medSpinner_valueChanged(int arg1);

    void on_naturalSpinner_valueChanged(int arg1);

    void on_navSpinner_valueChanged(int arg1);

    void on_occultSpinner_valueChanged(int arg1);

    void on_hvMacSpinner_valueChanged(int arg1);

    void on_persuadeSpinner_valueChanged(int arg1);

    void on_pilotSpinner_valueChanged(int arg1);

    void on_psySpinner_valueChanged(int arg1);

    void on_psychanalySpinner_valueChanged(int arg1);

    void on_rideSpinner_valueChanged(int arg1);

    void on_scienceSpinner_valueChanged(int arg1);

    void on_sleightSpinner_valueChanged(int arg1);

    void on_spotSpinner_valueChanged(int arg1);

    void on_stealthSpinner_valueChanged(int arg1);

    void on_survivalSpinner_valueChanged(int arg1);

    void on_swimSpinner_valueChanged(int arg1);

    void on_throwSpinner_valueChanged(int arg1);

    void on_trackSpinner_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_luckSpinbox_valueChanged(int arg1);

    void on_buildSpinbox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    character currCharacter;

    void generateRandomCharacter();
    void updateSanity();

    void setValue(void *val, void *newVal);
    void print(QString str);
};

#endif // MAINWINDOW_H
