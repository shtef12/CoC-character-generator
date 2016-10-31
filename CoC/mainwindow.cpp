#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hpSpinbox->setRange(0,20);
    updateSanity();
    ui->mpSpinbox->setRange(0,24);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateRandomCharacter()
{
    currCharacter.resetSkills();
    currCharacter.generateRandomCharacter();

    //show the base characteristics
    ui->strSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Strength));
    ui->dexSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Dexterity));
    ui->conSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Constitution));
    ui->sizSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Size));
    ui->appSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Appearance));
    ui->eduSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Education));
    ui->intSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Intelligence));
    ui->powSpinbox->setValue(currCharacter.getCharacteristicValue(CharacteristicName::Power));
    ui->hpSpinbox->setValue(currCharacter.getHitPoints());
    ui->mpSpinbox->setValue(currCharacter.getMagicPoints());
    ui->sanitySpinbox->setValue(currCharacter.getSanity());
    ui->luckSpinbox->setValue(currCharacter.getLuck());

    //show the name of the character
    ui->firstNameEdit->setText(currCharacter.name);

    //show the age
    ui->ageSpinBox->setValue(currCharacter.age);

    //show damage bonus and build
    ui->buildSpinbox->setValue(currCharacter.getBuild());
    ui->dmgBonusLab->setText(currCharacter.getDamageBonus());

    //show the character skill values
    ui->acctSpinner->setValue(currCharacter.getSkillValue(SkillNames::Accounting));
    ui->anthroSpinner->setValue(currCharacter.getSkillValue(SkillNames::Anthropology));
    ui->appraiseSpinner->setValue(currCharacter.getSkillValue(SkillNames::Appraise));
    ui->archaeologySpinner->setValue(currCharacter.getSkillValue(SkillNames::Archaeology));
    ui->artSpinner->setValue(currCharacter.getSkillValue(SkillNames::Art));
    ui->charmSpinner->setValue(currCharacter.getSkillValue(SkillNames::Charm));
    ui->climbSpinner->setValue(currCharacter.getSkillValue(SkillNames::Climb));
    ui->creditRateSpinner->setValue(currCharacter.getSkillValue(SkillNames::Credit_Rating));
    ui->cthulhuMythosSpinner->setValue(currCharacter.getSkillValue(SkillNames::Cthulhu_Mythos));
    ui->disguiseSpinner->setValue(currCharacter.getSkillValue(SkillNames::Disguise));
    ui->dodgeSpinner->setValue(currCharacter.getSkillValue(SkillNames::Dodge));
    ui->driveSpinner->setValue(currCharacter.getSkillValue(SkillNames::Drive));
    ui->elecRepairSpinner->setValue(currCharacter.getSkillValue(SkillNames::Elec_Repair));
    ui->fastTalkSpinner->setValue(currCharacter.getSkillValue(SkillNames::Fast_Talk));
    ui->brawlSpinner->setValue(currCharacter.getSkillValue(SkillNames::Fighting_Brawl));
    ui->handgunSpinner->setValue(currCharacter.getSkillValue(SkillNames::Firearms_Handgun));
    ui->rifleSpinner->setValue(currCharacter.getSkillValue(SkillNames::Firearms_Rifle));
    ui->firstAidSpinner->setValue(currCharacter.getSkillValue(SkillNames::First_Aid));
    ui->historySpinner->setValue(currCharacter.getSkillValue(SkillNames::History));
    ui->intimidateSpinner->setValue(currCharacter.getSkillValue(SkillNames::Intimidate));
    ui->jumpSpinner->setValue(currCharacter.getSkillValue(SkillNames::Jump));
    ui->langOtherSpinner->setValue(currCharacter.getSkillValue(SkillNames::Language_Other));
    ui->langOwnSpinner->setValue(currCharacter.getSkillValue(SkillNames::Language_Own));
    ui->lawSpinner->setValue(currCharacter.getSkillValue(SkillNames::Law));
    ui->librarySpinner->setValue(currCharacter.getSkillValue(SkillNames::Library_Use));
    ui->listenSpinner->setValue(currCharacter.getSkillValue(SkillNames::Listen));
    ui->lockSpinner->setValue(currCharacter.getSkillValue(SkillNames::Locksmith));
    ui->mRepairSpinner->setValue(currCharacter.getSkillValue(SkillNames::Mech_Repair));
    ui->medSpinner->setValue(currCharacter.getSkillValue(SkillNames::Medicine));
    ui->naturalSpinner->setValue(currCharacter.getSkillValue(SkillNames::Natural_World));
    ui->navSpinner->setValue(currCharacter.getSkillValue(SkillNames::Navigate));
    ui->occultSpinner->setValue(currCharacter.getSkillValue(SkillNames::Occult));
    ui->hvMacSpinner->setValue(currCharacter.getSkillValue(SkillNames::Op_Heavy_Machine));
    ui->persuadeSpinner->setValue(currCharacter.getSkillValue(SkillNames::Persuade));
    ui->pilotSpinner->setValue(currCharacter.getSkillValue(SkillNames::Pilot));
    ui->psySpinner->setValue(currCharacter.getSkillValue(SkillNames::Psychology));
    ui->psychanalySpinner->setValue(currCharacter.getSkillValue(SkillNames::Psychoanalysis));
    ui->rideSpinner->setValue(currCharacter.getSkillValue(SkillNames::Ride));
    ui->scienceSpinner->setValue(currCharacter.getSkillValue(SkillNames::Science));
    ui->sleightSpinner->setValue(currCharacter.getSkillValue(SkillNames::Sleight_of_Hand));
    ui->spotSpinner->setValue(currCharacter.getSkillValue(SkillNames::Spot_Hidden));
    ui->stealthSpinner->setValue(currCharacter.getSkillValue(SkillNames::Stealth));
    ui->survivalSpinner->setValue(currCharacter.getSkillValue(SkillNames::Survival));
    ui->swimSpinner->setValue(currCharacter.getSkillValue(SkillNames::Swim));
    ui->throwSpinner->setValue(currCharacter.getSkillValue(SkillNames::Throw));
    ui->trackSpinner->setValue(currCharacter.getSkillValue(SkillNames::Track));
}

void MainWindow::updateSanity()
{
    int maxSanity = 99 - currCharacter.getSkillValue(SkillNames::Cthulhu_Mythos);
    ui->sanitySpinbox->setRange(0,maxSanity);
}

void MainWindow::print(QString str)
{
    std::cout << str.toStdString() << std::endl;
}

void MainWindow::on_pushButton_clicked()
{
    //TODO: generate a random character
    generateRandomCharacter();
}

void MainWindow::on_firstNameEdit_returnPressed()
{
    currCharacter.name = ui->firstNameEdit->text();
    //print(currCharacter.name);
}

void MainWindow::on_ageSpinBox_valueChanged(int arg1)
{
    currCharacter.age = arg1;
    //print(QString::number(arg1));
}

void MainWindow::on_occupationEdit_returnPressed()
{
    currCharacter.occupation = ui->occupationEdit->text();
}

void MainWindow::on_residenceEdit_returnPressed()
{
    currCharacter.residence = ui->residenceEdit->text();
}

void MainWindow::on_birthplaceEdit_returnPressed()
{
    currCharacter.birthplace = ui->birthplaceEdit->text();
}

void MainWindow::on_strSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Strength, arg1);
}

void MainWindow::on_dexSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Dexterity, arg1);
}

void MainWindow::on_intSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Intelligence, arg1);
}

void MainWindow::on_conSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Constitution, arg1);
}

void MainWindow::on_appSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Appearance, arg1);
}

void MainWindow::on_powSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Power, arg1);
}

void MainWindow::on_sizSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Size, arg1);
}

void MainWindow::on_eduSpinbox_valueChanged(int arg1)
{
    currCharacter.chars.setValue(CharacteristicName::Education, arg1);
}

void MainWindow::on_hpSpinbox_valueChanged(int arg1)
{
    currCharacter.setHitPoints(arg1);
}

void MainWindow::on_sanitySpinbox_valueChanged(int arg1)
{
    currCharacter.setSanity(arg1);
}

void MainWindow::on_mpSpinbox_valueChanged(int arg1)
{
    currCharacter.setMagicPoints(arg1);
}

void MainWindow::on_notesEdit_textChanged()
{
    currCharacter.notes = ui->notesEdit->toPlainText();
}

void MainWindow::on_descEdit_textChanged()
{
    currCharacter.description = ui->descEdit->toPlainText();
}

void MainWindow::on_beliefEdit_textChanged()
{
    currCharacter.beliefs = ui->beliefEdit->toPlainText();
}

void MainWindow::on_sigPplEdit_textChanged()
{
    currCharacter.significantPeople = ui->sigPplEdit->toPlainText();
}

void MainWindow::on_locEdit_textChanged()
{
    currCharacter.meaningfulLocations = ui->locEdit->toPlainText();
}

void MainWindow::on_possEdit_textChanged()
{
    currCharacter.treasuredPossessions = ui->possEdit->toPlainText();
}

void MainWindow::on_traitEdit_textChanged()
{
    currCharacter.traits = ui->traitEdit->toPlainText();
}

void MainWindow::on_injEdit_textChanged()
{
    currCharacter.injuries = ui->injEdit->toPlainText();
}

void MainWindow::on_fearEdit_textChanged()
{
    currCharacter.phobiaManias = ui->fearEdit->toPlainText();
}

void MainWindow::on_gearEdit_textChanged()
{
    currCharacter.gear = ui->gearEdit->toPlainText();
}

void MainWindow::on_spellEdit_textChanged()
{
    currCharacter.spellsArtifacts = ui->spellEdit->toPlainText();
}

void MainWindow::on_encounterEdit_textChanged()
{
    currCharacter.strangeEncounters = ui->encounterEdit->toPlainText();
}

void MainWindow::on_acctSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Accounting,arg1);
}


void MainWindow::on_anthroSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Anthropology,arg1);
}

void MainWindow::on_appraiseSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Appraise,arg1);
}

void MainWindow::on_archaeologySpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Archaeology,arg1);
}

void MainWindow::on_artSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Art,arg1);
}

void MainWindow::on_charmSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Charm,arg1);
}

void MainWindow::on_climbSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Climb,arg1);
}

void MainWindow::on_creditRateSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Credit_Rating,arg1);
}

void MainWindow::on_cthulhuMythosSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Cthulhu_Mythos,arg1);
    updateSanity();
}

void MainWindow::on_disguiseSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Disguise,arg1);
}

void MainWindow::on_dodgeSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Dodge,arg1);
}

void MainWindow::on_driveSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Drive,arg1);
}

void MainWindow::on_elecRepairSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Elec_Repair,arg1);
}

void MainWindow::on_fastTalkSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Fast_Talk,arg1);
}

void MainWindow::on_brawlSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Fighting_Brawl,arg1);
}

void MainWindow::on_handgunSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Firearms_Handgun,arg1);
}

void MainWindow::on_rifleSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Firearms_Rifle,arg1);
}

void MainWindow::on_firstAidSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::First_Aid,arg1);
}

void MainWindow::on_historySpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::History,arg1);
}

void MainWindow::on_intimidateSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Intimidate,arg1);
}

void MainWindow::on_jumpSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Jump,arg1);
}

void MainWindow::on_langOtherSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Language_Other,arg1);
}

void MainWindow::on_langOwnSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Language_Own,arg1);
}

void MainWindow::on_lawSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Law,arg1);
}

void MainWindow::on_librarySpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Library_Use,arg1);
}

void MainWindow::on_listenSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Listen,arg1);
}

void MainWindow::on_lockSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Locksmith,arg1);
}

void MainWindow::on_mRepairSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Mech_Repair,arg1);
}

void MainWindow::on_medSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Medicine,arg1);
}

void MainWindow::on_naturalSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Natural_World,arg1);
}

void MainWindow::on_navSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Navigate,arg1);
}

void MainWindow::on_occultSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Occult,arg1);
}

void MainWindow::on_hvMacSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Op_Heavy_Machine,arg1);
}

void MainWindow::on_persuadeSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Persuade,arg1);
}

void MainWindow::on_pilotSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Pilot,arg1);
}

void MainWindow::on_psySpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Psychology,arg1);
}

void MainWindow::on_psychanalySpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Psychoanalysis,arg1);
}

void MainWindow::on_rideSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Ride,arg1);
}

void MainWindow::on_scienceSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Science,arg1);
}

void MainWindow::on_sleightSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Sleight_of_Hand,arg1);
}

void MainWindow::on_spotSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Spot_Hidden,arg1);
}

void MainWindow::on_stealthSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Stealth,arg1);
}

void MainWindow::on_survivalSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Survival,arg1);
}

void MainWindow::on_swimSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Swim,arg1);
}

void MainWindow::on_throwSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Throw,arg1);
}

void MainWindow::on_trackSpinner_valueChanged(int arg1)
{
    currCharacter.setSkillValue(SkillNames::Track,arg1);
}

void MainWindow::on_luckSpinbox_valueChanged(int arg1)
{
    currCharacter.setLuck(arg1);
}

void MainWindow::on_buildSpinbox_valueChanged(int arg1)
{
    currCharacter.setBuild(arg1);
}
