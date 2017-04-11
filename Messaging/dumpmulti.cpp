#include "dumpmulti.h"

DumpMulti::DumpMulti():Blofable(425,0x11)
{
    setAdressContent();
    setDataContent();
    setChecksum();
}
void DumpMulti::setMultiNumber(int num){
    setWordValue(6,num);
}

int DumpMulti::getMultiNumber(){
    return getWordValue(6);
}


QString DumpMulti::getMultiName()
{
    int offset=7;
    QString s="";
    for(int i=0;i<16;i++)
    {
        s+= (char)getWordValue(i+offset);
    }
    return s;
}


void  DumpMulti::setMultiName(QString name){
    int offset=7;
    for(int i=0; i<16 && name.length()>i;i++)
    {
        char c ;
        if(i >= name.length()){
            c = (char)0x20;
        }
        else{
            c = name.at(i).toAscii();
        }
        const char res(c);
        setWordValue(i+offset,res);
    }
}

int DumpMulti::getMultiTempo(){
    return _mots.at(24)->getValue();
}

void DumpMulti::setMultiTempo(int value){
    _mots.at(24)->setValue(value);

}

int DumpMulti::getMultiVolume(){
    return _mots.at(23)->getValue();
}

void DumpMulti::setMultiVolume(int value){
    _mots.at(23)->setValue(value);
}

#include "BlofeldMgr/blofchannel.h"

void DumpMulti::fromChannel(BlofChannel *ch, int chid)
{
    int offset = 25;
    for(int i(0);i<21;i++){
       _mots.at( offset + i*chid)->setValue(ch->getParametreValue(i));
    }
}

void DumpMulti::initChannel(BlofChannel *ch, int chid)
{
    int offset = 25;
    for(int i(0);i<21;i++){
        int wordoffset = i + chid * 21;
        ch->_multiPars.append
        (
            Parametre(dynamic_cast<ValueEnum*>(( _mots.at( wordoffset + offset )->getValueMgr())),wordoffset )
        );
    }
}


void DumpMulti::toChannel(BlofChannel *ch, int chid)
{
    int offset = 25;
    for(int i(0);i<21;i++){
        int wordoffset = i + chid * 21;
        ch->setParametreValue(i,_mots.at( wordoffset + offset )->getValue());
    }
}


void DumpMulti::setChecksum()
{
    appenWord(new WordChecksum (&_message ,423,7,422));
}

void DumpMulti::addParametre(WordWriter * w)
{
    appenWord(w);
}

void DumpMulti::setAdressContent()
{
    appenWord (new WordConstante("unused",&_message[5],0));
    appenWord (new WordAny("Multi Number",&_message[6]));
}

void DumpMulti::setDataContent()
{
    for(int i(0);i<16;i++){
        QString s;
        s.sprintf("CHAR%2d",i);
        addParametre(new WordEnum(s,&_message[7+i], BLOT_CHARZ));
    }
    addParametre(new WordEnum("GLOBAL VOL.",&_message[24], BLOT_STANDARD));
    addParametre(new WordEnum("TEMPO",&_message[25], BLOT_TEMPO));
    for(int i(0);i<16;i++)
    {
        int offset = 24*i;
        addParametre(new WordEnum("Banknum"   ,&_message[39+offset], BLOT_BANK));
        addParametre(new WordEnum("PgmNum"    ,&_message[40+offset], BLOT_STANDARD));
        addParametre(new WordEnum("Vol."      ,&_message[41+offset], BLOT_STANDARD));
        addParametre(new WordEnum("pan."      ,&_message[42+offset], BLOT_PAN));
        addParametre(new WordEnum("TRANSPOSE" ,&_message[44+offset], BLOT_GLOB_TRANSPOSE));
        addParametre(new WordEnum("DETUNE"    ,&_message[45+offset], BLOT_CENTERED));
        addParametre(new WordEnum("CHANNEL"   ,&_message[46+offset], BLOT_MULTI_CHANNEL));
        addParametre(new WordEnum("Low Note"  ,&_message[47+offset], BLOT_MULTI_NOTE));
        addParametre(new WordEnum("High Note" ,&_message[48+offset], BLOT_MULTI_NOTE));
        addParametre(new WordEnum("low Vel"   ,&_message[49+offset], BLOT_VOLFROM1));
        addParametre(new WordEnum("high Vel"  ,&_message[50+offset], BLOT_VOLFROM1));
        addParametre(new WordEnum("Status"    ,&_message[51+offset], BLOT_SWITCH,1,6));
        addParametre(new WordEnum("MIDI"      ,&_message[51+offset], BLOT_SWITCH,1,0));
        addParametre(new WordEnum("USB"       ,&_message[51+offset], BLOT_SWITCH,1,1));
        addParametre(new WordEnum("LOCAL"     ,&_message[51+offset], BLOT_SWITCH,1,2));
        addParametre(new WordEnum("pitchBend" ,&_message[52+offset], BLOT_SWITCH,1,0));
        addParametre(new WordEnum("modwhell"  ,&_message[52+offset], BLOT_SWITCH,1,1));
        addParametre(new WordEnum("pressure"  ,&_message[52+offset], BLOT_SWITCH,1,2));
        addParametre(new WordEnum("sustain"   ,&_message[52+offset], BLOT_SWITCH,1,3));
        addParametre(new WordEnum("edits"     ,&_message[52+offset], BLOT_SWITCH,1,4));
        addParametre(new WordEnum("PGMCH"     ,&_message[52+offset], BLOT_SWITCH,1,5));
    }
}