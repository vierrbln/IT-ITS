#include <windows.h>
#include <cviauto.h>
#include <ansi_c.h>
#include "toolbox.h"
#include <utility.h>
#include <cvirte.h>		
#include <userint.h>
#include "InstallTool.h"
#include "Splash.h"

//Version 1.0.0.1  Göpel Library dazugefügt...
//Version 1.0.0.2  HardDisc-ID auslesen. 
//                 Regsitrationpanel von AE-ITS hinzugefügt
//                 CFg-File Flag zu  kopieren hinzugefügt
//Version 1.0.0.3  Teststand 2012...
//Version 1.0.0.4  Lizensierung CP-ITS einzeln für Prettl..
//Version 1.0.0.5  Neu-Kompilirierung unter CVI 2013.   
//Version 1.0.0.6  Neuordnung der TeststandOrdner

#define VERSION "1.1.0.0"

#define TESTSTAND_4_0  0
#define TESTSTAND_4_1  1
#define TESTSTAND_4_2  2
#define TESTSTAND_4_21 3
#define TESTSTAND_4_5  4
#define TESTSTAND_4_5_SP1  5
#define TESTSTAND_5_0  6
#define TESTSTAND_5_1  7
#define TESTSTAND_14_0_32  8
#define TESTSTAND_14_0_64  9
#define TESTSTAND_16_0_32  10
#define TESTSTAND_16_0_64  11
#define TESTSTAND_17_0_32  12
#define TESTSTAND_17_0_64  13
#define TESTSTAND_19_0_32  14
#define TESTSTAND_19_0_64  15
#define TESTSTAND_20_0_32  16
#define TESTSTAND_20_0_64  17

#define XP_GERMAN 0
#define XP_ENGLISH 1
#define WIN_7 2
#define WIN_8 3
#define WIN_10 4



#define RS_DOCS "C:\\Users\\Public\\Documents\\Rohde-Schwarz\\"
#define SW_DOCS "C:\\Users\\Public\\Documents\\SW-ITS\\"


#define SWITS_XP_GER "C:\\Programme\\SW-ITS\\"
#define SWITS_XP_ENG "C:\\Program Files\\SW-ITS\\" 
#define SWITS_WIN_7 "C:\\Program Files (x86)\\SW-ITS\\"
#define SWITS_WIN_8 "C:\\Program Files (x86)\\SW-ITS\\"
#define SWITS_WIN_10 "C:\\Program Files (x86)\\SW-ITS\\"

#define RS_XP_GER "C:\\Programme\\Rohde-Schwarz\\GTSL\\"
#define RS_XP_ENG "C:\\Program Files\\Rohde-Schwarz\\GTSL\\" 
#define RS_WIN_7 "C:\\Program Files (x86)\\Rohde-Schwarz\\GTSL\\"
#define RS_WIN_8 "C:\\Program Files (x86)\\Rohde-Schwarz\\GTSL\\"
#define RS_WIN_10 "C:\\Program Files (x86)\\Rohde-Schwarz\\GTSL\\"





#define TESTSTAND_4_0_GER_CONFIG "C:\\Programme\\National Instruments\\TestStand 4.0\\Cfg\\"
#define TESTSTAND_4_0_GER_ICON "C:\\Programme\\National Instruments\\TestStand 4.0\\Components\\User\\Icons\\"
#define TESTSTAND_4_0_GER_TYPES "C:\\Programme\\National Instruments\\TestStand 4.0\\Components\\User\\TypePalettes\\"

#define TESTSTAND_4_0_ENG_CONFIG "C:\\Program Files\\National Instruments\\TestStand 4.0\\Cfg\\"
#define TESTSTAND_4_0_ENG_ICON "C:\\Program Files\\National Instruments\\TestStand 4.0\\Components\\User\\Icons\\"
#define TESTSTAND_4_0_ENG_TYPES "C:\\Program Files\\National Instruments\\TestStand 4.0\\Components\\User\\TypePalettes\\"

#define TESTSTAND_4_0_WIN7_CONFIG "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Cfg\\"
#define TESTSTAND_4_0_WIN7_ICON "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\Icons\\"
#define TESTSTAND_4_0_WIN7_TYPES "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\TypePalettes\\"

#define TESTSTAND_4_0_WIN8_CONFIG "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Cfg\\"
#define TESTSTAND_4_0_WIN8_ICON "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\Icons\\"
#define TESTSTAND_4_0_WIN8_TYPES "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\TypePalettes\\"

#define TESTSTAND_4_0_WIN10_CONFIG "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Cfg\\"
#define TESTSTAND_4_0_WIN10_ICON "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\Icons\\"
#define TESTSTAND_4_0_WIN10_TYPES "C:\\Program Files (x86)\\National Instruments\\TestStand 4.0\\Components\\User\\TypePalettes\\"

#define TESTSTAND_4_0_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.0\\"
#define TESTSTAND_4_0_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 4.0\\"



#define TESTSTAND_4_1_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 4.1\\Cfg\\"
#define TESTSTAND_4_1_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.1\\Components\\Icons\\"
#define TESTSTAND_4_1_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_1_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 4.1\\Cfg\\"
#define TESTSTAND_4_1_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.1\\Components\\Icons\\"
#define TESTSTAND_4_1_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_1_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.1\\Cfg\\"
#define TESTSTAND_4_1_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\Icons\\"
#define TESTSTAND_4_1_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_1_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.1\\Cfg\\"
#define TESTSTAND_4_1_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\Icons\\"
#define TESTSTAND_4_1_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_1_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.1\\Cfg\\"
#define TESTSTAND_4_1_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\Icons\\"
#define TESTSTAND_4_1_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_1_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.1\\"
#define TESTSTAND_4_1_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 4.1\\"



#define TESTSTAND_4_2_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 4.2\\Cfg\\"
#define TESTSTAND_4_2_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.2\\Components\\Icons\\"
#define TESTSTAND_4_2_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.2\\Components\\TypePalettes\\"

#define TESTSTAND_4_2_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 4.2\\Cfg\\"
#define TESTSTAND_4_2_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.2\\Components\\Icons\\"
#define TESTSTAND_4_2_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.2\\Components\\TypePalettes\\"

#define TESTSTAND_4_2_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2\\Cfg\\"
#define TESTSTAND_4_2_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\Icons\\"
#define TESTSTAND_4_2_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\TypePalettes\\"

#define TESTSTAND_4_2_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2\\Cfg\\"
#define TESTSTAND_4_2_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\Icons\\"
#define TESTSTAND_4_2_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\TypePalettes\\"

#define TESTSTAND_4_2_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2\\Cfg\\"
#define TESTSTAND_4_2_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\Icons\\"
#define TESTSTAND_4_2_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\Components\\TypePalettes\\"

#define TESTSTAND_4_2_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2\\"
#define TESTSTAND_4_2_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 4.2\\"



#define TESTSTAND_4_21_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 4.2.1\\Cfg\\"
#define TESTSTAND_4_21_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.2.1\\Components\\Icons\\"
#define TESTSTAND_4_21_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 4.2.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_21_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 4.2.1\\Cfg\\"
#define TESTSTAND_4_21_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\Icons\\"
#define TESTSTAND_4_21_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_21_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2.1\\Cfg\\"
#define TESTSTAND_4_21_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\Icons\\"
#define TESTSTAND_4_21_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_21_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2.1\\Cfg\\"
#define TESTSTAND_4_21_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\Icons\\"
#define TESTSTAND_4_21_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_21_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 4.2.1\\Cfg\\"
#define TESTSTAND_4_21_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\Icons\\"
#define TESTSTAND_4_21_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\Components\\TypePalettes\\"

#define TESTSTAND_4_21_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 4.2.1\\"
#define TESTSTAND_4_21_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 4.2.1\\"



#define TESTSTAND_4_5_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2010\\Cfg\\"
#define TESTSTAND_4_5_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2010\\Components\\Icons\\"
#define TESTSTAND_4_5_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2010\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2010\\Cfg\\"
#define TESTSTAND_4_5_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2010\\Components\\Icons\\"
#define TESTSTAND_4_5_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2010\\Components\\TypePalettes\\"
								
#define TESTSTAND_4_5_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010\\Cfg\\"
#define TESTSTAND_4_5_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\Icons\\"
#define TESTSTAND_4_5_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010\\Cfg\\"
#define TESTSTAND_4_5_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\Icons\\"
#define TESTSTAND_4_5_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010\\Cfg\\"
#define TESTSTAND_4_5_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\Icons\\"
#define TESTSTAND_4_5_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010\\"
#define TESTSTAND_4_5_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2010\\"



#define TESTSTAND_4_5_SP1_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2010 SP1\\Cfg\\"
#define TESTSTAND_4_5_SP1_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2010 SP1\\Components\\Icons\\"
#define TESTSTAND_4_5_SP1_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2010 SP1\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_SP1_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2010 SP1\\Cfg\\"
#define TESTSTAND_4_5_SP1_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\Icons\\"
#define TESTSTAND_4_5_SP1_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_SP1_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010 SP1\\Cfg\\"
#define TESTSTAND_4_5_SP1_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\Icons\\"
#define TESTSTAND_4_5_SP1_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_SP1_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010 SP1\\Cfg\\"
#define TESTSTAND_4_5_SP1_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\Icons\\"
#define TESTSTAND_4_5_SP1_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_SP1_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2010 SP1\\Cfg\\"
#define TESTSTAND_4_5_SP1_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\Icons\\"
#define TESTSTAND_4_5_SP1_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\Components\\TypePalettes\\"

#define TESTSTAND_4_5_SP1_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2010 SP1\\"
#define TESTSTAND_4_5_SP1_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2010 SP1\\"



#define TESTSTAND_5_0_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2012\\Cfg\\"
#define TESTSTAND_5_0_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2012\\Components\\Icons\\"
#define TESTSTAND_5_0_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2012\\Components\\TypePalettes\\"

#define TESTSTAND_5_0_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2012\\Cfg\\"
#define TESTSTAND_5_0_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2012\\Components\\Icons\\"
#define TESTSTAND_5_0_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2012\\Components\\TypePalettes\\"

#define TESTSTAND_5_0_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2012\\Cfg\\"
#define TESTSTAND_5_0_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\Icons\\"
#define TESTSTAND_5_0_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\TypePalettes\\"

#define TESTSTAND_5_0_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2012\\Cfg\\"
#define TESTSTAND_5_0_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\Icons\\"
#define TESTSTAND_5_0_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\TypePalettes\\"

#define TESTSTAND_5_0_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2012\\Cfg\\"
#define TESTSTAND_5_0_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\Icons\\"
#define TESTSTAND_5_0_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\Components\\TypePalettes\\"

#define TESTSTAND_5_0_SP1_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2012\\"
#define TESTSTAND_5_0_SP1_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2012\\"



#define TESTSTAND_5_1_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2013\\Cfg\\"
#define TESTSTAND_5_1_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2013\\Components\\Icons\\"
#define TESTSTAND_5_1_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2013\\Components\\TypePalettes\\"

#define TESTSTAND_5_1_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2013\\Cfg\\"
#define TESTSTAND_5_1_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2013\\Components\\Icons\\"
#define TESTSTAND_5_1_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2013\\Components\\TypePalettes\\"

#define TESTSTAND_5_1_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2013\\Cfg\\"
#define TESTSTAND_5_1_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\Icons\\"
#define TESTSTAND_5_1_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\TypePalettes\\"

#define TESTSTAND_5_1_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2013\\Cfg\\"
#define TESTSTAND_5_1_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\Icons\\"
#define TESTSTAND_5_1_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\TypePalettes\\"

#define TESTSTAND_5_1_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2013\\Cfg\\"
#define TESTSTAND_5_1_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\Icons\\"
#define TESTSTAND_5_1_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\Components\\TypePalettes\\"

#define TESTSTAND_5_1_SP1_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2013\\"
#define TESTSTAND_5_1_SP1_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2013\\"



#define TESTSTAND_14_0_32BIT_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2014 (32-bit)\\Cfg\\"
#define TESTSTAND_14_0_32BIT_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2014\\Components (32-bit)\\Icons\\"
#define TESTSTAND_14_0_32BIT_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2014\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_14_0_32BIT_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2014 (32-bit)\\Cfg\\"
#define TESTSTAND_14_0_32BIT_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2014\\Components (32-bit)\\Icons\\"
#define TESTSTAND_14_0_32BIT_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2014\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_14_0_32BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (32-bit)\\Cfg\\"
#define TESTSTAND_14_0_32BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_32BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_32BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (32-bit)\\Cfg\\"
#define TESTSTAND_14_0_32BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_32BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_32BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (32-bit)\\Cfg\\"
#define TESTSTAND_14_0_32BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_32BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_32BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (32-bit)\\"
#define TESTSTAND_14_0_32BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2014 (32-bit)\\"



#define TESTSTAND_16_0_32BIT_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2016 (32-bit)\\Cfg\\"
#define TESTSTAND_16_0_32BIT_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2016\\Components (32-bit)\\Icons\\"
#define TESTSTAND_16_0_32BIT_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2016\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_16_0_32BIT_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2016 (32-bit)\\Cfg\\"
#define TESTSTAND_16_0_32BIT_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2016\\Components (32-bit)\\Icons\\"
#define TESTSTAND_16_0_32BIT_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2016\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_16_0_32BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (32-bit)\\Cfg\\"
#define TESTSTAND_16_0_32BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_32BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_32BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (32-bit)\\Cfg\\"
#define TESTSTAND_16_0_32BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_32BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_32BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (32-bit)\\Cfg\\"
#define TESTSTAND_16_0_32BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_32BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_32BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (32-bit)\\"
#define TESTSTAND_16_0_32BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2016 (32-bit)\\"



#define TESTSTAND_17_0_32BIT_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2017 (32-bit)\\Cfg\\"
#define TESTSTAND_17_0_32BIT_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2017\\Components (32-bit)\\Icons\\"
#define TESTSTAND_17_0_32BIT_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2017\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_17_0_32BIT_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2017 (32-bit)\\Cfg\\"
#define TESTSTAND_17_0_32BIT_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2017\\Components (32-bit)\\Icons\\"
#define TESTSTAND_17_0_32BIT_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2017\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_17_0_32BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (32-bit)\\Cfg\\"
#define TESTSTAND_17_0_32BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_32BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_32BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (32-bit)\\Cfg\\"
#define TESTSTAND_17_0_32BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_32BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_32BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (32-bit)\\Cfg\\"
#define TESTSTAND_17_0_32BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_32BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_32BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (32-bit)\\"
#define TESTSTAND_17_0_32BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2017 (32-bit)\\"



#define TESTSTAND_19_0_32BIT_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2019 (32-bit)\\Cfg\\"
#define TESTSTAND_19_0_32BIT_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2019\\Components (32-bit)\\Icons\\"
#define TESTSTAND_19_0_32BIT_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2019\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_19_0_32BIT_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2019 (32-bit)\\Cfg\\"
#define TESTSTAND_19_0_32BIT_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2019\\Components (32-bit)\\Icons\\"
#define TESTSTAND_19_0_32BIT_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2019\\Components (32-bit)\\TypePalettes\\"
				
#define TESTSTAND_19_0_32BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (32-bit)\\Cfg\\"
#define TESTSTAND_19_0_32BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_32BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_32BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (32-bit)\\Cfg\\"
#define TESTSTAND_19_0_32BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_32BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_32BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (32-bit)\\Cfg\\"
#define TESTSTAND_19_0_32BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_32BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_32BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (32-bit)\\"
#define TESTSTAND_19_0_32BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2019 (32-bit)\\"



#define TESTSTAND_20_0_32BIT_GER_CONFIG "C:\\Dokumente und Einstellungen\\All Users\\Anwendungsdaten\\National Instruments\\TestStand 2020 (32-bit)\\Cfg\\"
#define TESTSTAND_20_0_32BIT_GER_ICON "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2020\\Components (32-bit)\\Icons\\"
#define TESTSTAND_20_0_32BIT_GER_TYPES "C:\\Dokumente und Einstellungen\\All Users\\Dokumente\\National Instruments\\TestStand 2020\\Components (32-bit)\\TypePalettes\\"

#define TESTSTAND_20_0_32BIT_ENG_CONFIG "C:\\Documents and Settings\\All Users\\Application Data\\National Instruments\\TestStand 2020 (32-bit)\\Cfg\\"
#define TESTSTAND_20_0_32BIT_ENG_ICON "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2020\\Components (32-bit)\\Icons\\"
#define TESTSTAND_20_0_32BIT_ENG_TYPES "C:\\Documents and Settings\\All Users\\Documents\\National Instruments\\TestStand 2020\\Components (32-bit)\\TypePalettes\\"
				
#define TESTSTAND_20_0_32BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (32-bit)\\Cfg\\"
#define TESTSTAND_20_0_32BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_32BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_32BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (32-bit)\\Cfg\\"
#define TESTSTAND_20_0_32BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_32BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_32BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (32-bit)\\Cfg\\"
#define TESTSTAND_20_0_32BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_32BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_32BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (32-bit)\\"
#define TESTSTAND_20_0_32BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2020 (32-bit)\\"



#define TESTSTAND_14_0_64BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (64-bit)\\Cfg\\"
#define TESTSTAND_14_0_64BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_64BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_64BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (64-bit)\\Cfg\\"
#define TESTSTAND_14_0_64BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_64BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_64BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2014 (64-bit)\\Cfg\\"
#define TESTSTAND_14_0_64BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_14_0_64BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_14_0_64BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2014 (64-bit)\\"
#define TESTSTAND_14_0_64BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2014 (64-bit)\\"



#define TESTSTAND_16_0_64BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (64-bit)\\Cfg\\"
#define TESTSTAND_16_0_64BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_64BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_64BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (64-bit)\\Cfg\\"
#define TESTSTAND_16_0_64BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_64BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_64BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2016 (64-bit)\\Cfg\\"
#define TESTSTAND_16_0_64BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_16_0_64BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_16_0_64BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2016 (64-bit)\\"
#define TESTSTAND_16_0_64BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2016 (64-bit)\\"



#define TESTSTAND_17_0_64BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (64-bit)\\Cfg\\"
#define TESTSTAND_17_0_64BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_64BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_64BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (64-bit)\\Cfg\\"
#define TESTSTAND_17_0_64BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_64BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_64BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2017 (64-bit)\\Cfg\\"
#define TESTSTAND_17_0_64BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_17_0_64BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_17_0_64BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2017 (64-bit)\\"
#define TESTSTAND_17_0_64BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2017 (64-bit)\\"



#define TESTSTAND_19_0_64BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (64-bit)\\Cfg\\"
#define TESTSTAND_19_0_64BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_64BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_64BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (64-bit)\\Cfg\\"
#define TESTSTAND_19_0_64BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_64BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_64BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2019 (64-bit)\\Cfg\\"
#define TESTSTAND_19_0_64BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_19_0_64BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_19_0_64BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2019 (64-bit)\\"
#define TESTSTAND_19_0_64BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2019 (64-bit)\\"



#define TESTSTAND_20_0_64BIT_WIN7_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (64-bit)\\Cfg\\"
#define TESTSTAND_20_0_64BIT_WIN7_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_64BIT_WIN7_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_64BIT_WIN8_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (64-bit)\\Cfg\\"
#define TESTSTAND_20_0_64BIT_WIN8_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_64BIT_WIN8_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_64BIT_WIN10_CONFIG "C:\\Users\\All Users\\National Instruments\\TestStand 2020 (64-bit)\\Cfg\\"
#define TESTSTAND_20_0_64BIT_WIN10_ICON "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\Icons\\"
#define TESTSTAND_20_0_64BIT_WIN10_TYPES "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\Components\\TypePalettes\\"

#define TESTSTAND_20_0_64BIT_BCK_DOCS "C:\\Users\\Public\\Documents\\National Instruments\\TestStand 2020 (64-bit)\\"
#define TESTSTAND_20_0_64BIT_BCK_DATA "C:\\ProgramData\\National Instruments\\TestStand 2020 (64-bit)\\"


static int iMainPanelHandle;
static int iMeDriverPanelHandle;
static int giRegistrationPanel;
static int iLogPanelHandle;
static int iSplashPanelHandle;
static int iBackupPanelHandle;
static int iMenuBarHandle; 
static int iFoldersModified;
static char gcSystemID[1024];
static char gcHardDiscID[1024];

static int iBatchFileIsSet;
static int iLogFileIsSet;
static int iBackupPathIsSet;

LPTSTR lpVolumeNameBuffer; // volume name buffer
DWORD nVolumeNameSize; // length of name buffer
DWORD lpVolumeSerialNumber; // volume serial number
DWORD lpMaximumComponentLength; // maximum file name length
DWORD lpFileSystemFlags; // file system options
LPTSTR lpFileSystemNameBuffer; // file system name buffer
DWORD nFileSystemNameSize;
BOOL error;
DWORD errorCode;

void SetFiles (int iActualVersion, int iActualLanguage) {
	
	SetCtrlVal (iMainPanelHandle, PANEL_MODIFYFOLDERS, 0);
	iFoldersModified = 0;  
	
	if (iActualVersion < 0) {
	 //SetCtrlAttribute (iMainPanelHandle, PANEL_LANGUAGE, ATTR_DIMMED, 1);
	 SetCtrlAttribute (iMainPanelHandle, PANEL_COPY, ATTR_DIMMED, 1);
	 SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_COPYCFGFILE, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CREATEBACKUP, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_MODIFYFOLDERS, ATTR_DIMMED, 1);
     SetMenuBarAttribute (iMenuBarHandle, MENUBAR_FILE_ROBOCOPY_BACKUP, ATTR_DIMMED, 1);
	} else {
	 //SetCtrlAttribute (iMainPanelHandle, PANEL_LANGUAGE, ATTR_DIMMED, 0);
	 SetCtrlAttribute (iMainPanelHandle, PANEL_COPY, ATTR_DIMMED, 0);
	 SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGSELBUTTON, ATTR_DIMMED, 1);
     SetCtrlAttribute (iMainPanelHandle, PANEL_COPYCFGFILE, ATTR_DIMMED, 0);
     SetCtrlAttribute (iMainPanelHandle, PANEL_CREATEBACKUP, ATTR_DIMMED, 0);
     SetCtrlAttribute (iMainPanelHandle, PANEL_MODIFYFOLDERS, ATTR_DIMMED, 0);
     SetMenuBarAttribute (iMenuBarHandle, MENUBAR_FILE_ROBOCOPY_BACKUP, ATTR_DIMMED, 0);
	}  
	if (iActualLanguage == XP_GERMAN)
	{
		SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, SWITS_XP_GER);
		SetMenuBarAttribute (iMenuBarHandle, MENUBAR_FILE_ROBOCOPY_BACKUP, ATTR_DIMMED, 1);
		switch (iActualVersion)
		{
			default: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
			    break;
			case TESTSTAND_4_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_0_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_0_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_0_GER_TYPES);
			    break;
			case TESTSTAND_4_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_1_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_1_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_1_GER_TYPES);
			    break;
			case TESTSTAND_4_2: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_2_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_2_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_2_GER_TYPES);
			    break;
			case TESTSTAND_4_21: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_21_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_21_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_21_GER_TYPES);
			    break;
			case TESTSTAND_4_5: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_GER_TYPES);
			    break;
			case TESTSTAND_4_5_SP1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_SP1_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_SP1_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_SP1_GER_TYPES);
			    break;
			case TESTSTAND_5_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_0_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_0_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_0_GER_TYPES);
			    break;
			case TESTSTAND_5_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_1_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_1_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_1_GER_TYPES);
			    break;
			case TESTSTAND_14_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_32BIT_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_32BIT_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_32BIT_GER_TYPES);
			    break;
			case TESTSTAND_16_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_32BIT_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_32BIT_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_32BIT_GER_TYPES);
			    break;
			case TESTSTAND_17_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_32BIT_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_32BIT_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_32BIT_GER_TYPES);
			    break;
			case TESTSTAND_19_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_32BIT_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_32BIT_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_32BIT_GER_TYPES);
			    break;
			case TESTSTAND_20_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_32BIT_GER_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_32BIT_GER_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_32BIT_GER_TYPES);
			    break;
		}
	} else if (iActualLanguage == XP_ENGLISH) {
		SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, SWITS_XP_ENG);
		SetMenuBarAttribute (iMenuBarHandle, MENUBAR_FILE_ROBOCOPY_BACKUP, ATTR_DIMMED, 1);
		switch (iActualVersion)
		{
			default: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
			    break;
			case TESTSTAND_4_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_0_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_0_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_0_ENG_TYPES);
			    break;
			case TESTSTAND_4_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_1_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_1_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_1_ENG_TYPES);
			    break;
			case TESTSTAND_4_2: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_2_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_2_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_2_ENG_TYPES);
			    break;
			case TESTSTAND_4_21: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_21_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_21_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_21_ENG_TYPES);
			    break;
			case TESTSTAND_4_5: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_ENG_TYPES);
			    break;
			case TESTSTAND_4_5_SP1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_SP1_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_SP1_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_SP1_ENG_TYPES);
			    break;
			case TESTSTAND_5_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_0_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_0_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_0_ENG_TYPES);
			    break;
			case TESTSTAND_5_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_1_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_1_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_1_ENG_TYPES);
			    break;
			case TESTSTAND_14_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_32BIT_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_32BIT_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_32BIT_ENG_TYPES);
			    break;
			case TESTSTAND_16_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_32BIT_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_32BIT_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_32BIT_ENG_TYPES);
			    break;
			case TESTSTAND_17_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_32BIT_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_32BIT_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_32BIT_ENG_TYPES);
			    break;
			case TESTSTAND_19_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_32BIT_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_32BIT_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_32BIT_ENG_TYPES);
			    break;
			case TESTSTAND_20_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_32BIT_ENG_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_32BIT_ENG_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_32BIT_ENG_TYPES);
			    break;
		}
	} else if (iActualLanguage == WIN_7) {
		SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, SWITS_WIN_7);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS, RS_WIN_10);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS_2, RS_DOCS);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS, SWITS_WIN_7);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS_2, SW_DOCS);
		switch (iActualVersion)
		{
			default: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, "");
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, "");
			    break;
			case TESTSTAND_4_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_0_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_0_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_0_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_0_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_0_BCK_DATA);
			    break;
			case TESTSTAND_4_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_1_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_1_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_1_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_1_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_1_BCK_DATA);
			    break;
			case TESTSTAND_4_2: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_2_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_2_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_2_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_2_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_2_BCK_DATA);
			    break;
			case TESTSTAND_4_21: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_21_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_21_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_21_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_21_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_21_BCK_DATA);
			    break;
			case TESTSTAND_4_5: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_5_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_5_BCK_DATA);
			    break;
			case TESTSTAND_4_5_SP1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_SP1_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_SP1_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_SP1_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_4_5_SP1_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_4_5_SP1_BCK_DATA);
			    break;
			case TESTSTAND_5_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_0_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_0_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_0_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_5_0_SP1_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_5_0_SP1_BCK_DATA);
			    break;
			case TESTSTAND_5_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_1_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_1_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_1_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_5_1_SP1_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_5_1_SP1_BCK_DATA);
			    break;
			case TESTSTAND_14_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_32BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_32BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_32BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_14_0_32BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_14_0_32BIT_BCK_DATA);
			    break;
			case TESTSTAND_14_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_64BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_64BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_64BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_14_0_64BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_14_0_64BIT_BCK_DATA);
			    break;
			case TESTSTAND_16_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_32BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_32BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_32BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_16_0_32BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_16_0_32BIT_BCK_DATA);
			    break;
			case TESTSTAND_16_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_64BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_64BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_64BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_16_0_64BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_16_0_64BIT_BCK_DATA);
			    break;
			case TESTSTAND_17_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_32BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_32BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_32BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_17_0_32BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_17_0_32BIT_BCK_DATA);
			    break;
			case TESTSTAND_17_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_64BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_64BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_64BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_17_0_64BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_17_0_64BIT_BCK_DATA);
			    break;
			case TESTSTAND_19_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_32BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_32BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_32BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_19_0_32BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_19_0_32BIT_BCK_DATA);
			    break;
			case TESTSTAND_19_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_64BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_64BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_64BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_19_0_64BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_19_0_64BIT_BCK_DATA);
			    break;
			case TESTSTAND_20_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_32BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_32BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_32BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_20_0_32BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_20_0_32BIT_BCK_DATA);
			    break;
			case TESTSTAND_20_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_64BIT_WIN7_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_64BIT_WIN7_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_64BIT_WIN7_TYPES);
			    SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI, TESTSTAND_20_0_64BIT_BCK_DOCS);
				SetCtrlVal(iBackupPanelHandle, CREATEBACK_NI_2, TESTSTAND_20_0_64BIT_BCK_DATA);
			    break;
		}	
	}  else if (iActualLanguage == WIN_8) {
		SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, SWITS_WIN_8);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS, RS_WIN_10);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS_2, RS_DOCS);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS, SWITS_WIN_7);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS_2, SW_DOCS);
		switch (iActualVersion)
		{
			default: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
			    break;
			case TESTSTAND_4_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_0_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_0_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_0_WIN8_TYPES);
			    break;
			case TESTSTAND_4_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_1_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_1_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_1_WIN8_TYPES);
			    break;
			case TESTSTAND_4_2: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_2_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_2_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_2_WIN8_TYPES);
			    break;
			case TESTSTAND_4_21: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_21_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_21_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_21_WIN8_TYPES);
			    break;
			case TESTSTAND_4_5: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_WIN8_TYPES);
			    break;
			case TESTSTAND_4_5_SP1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_SP1_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_SP1_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_SP1_WIN8_TYPES);
			    break;
			case TESTSTAND_5_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_0_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_0_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_0_WIN8_TYPES);
			    break;
			case TESTSTAND_5_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_1_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_1_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_1_WIN8_TYPES);
			    break;
			case TESTSTAND_14_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_32BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_32BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_32BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_14_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_64BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_64BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_64BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_16_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_32BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_32BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_32BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_16_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_64BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_64BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_64BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_17_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_32BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_32BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_32BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_17_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_64BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_64BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_64BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_19_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_32BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_32BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_32BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_19_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_64BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_64BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_64BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_20_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_32BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_32BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_32BIT_WIN8_TYPES);
			    break;
			case TESTSTAND_20_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_64BIT_WIN8_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_64BIT_WIN8_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_64BIT_WIN8_TYPES);
			    break;
		}	
	} else if (iActualLanguage == WIN_10) {
		SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, SWITS_WIN_10);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS, RS_WIN_10);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_RS_2, RS_DOCS);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS, SWITS_WIN_7);
		SetCtrlVal(iBackupPanelHandle, CREATEBACK_SWITS_2, SW_DOCS);
		switch (iActualVersion)
		{
			default: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
			    break;
			case TESTSTAND_4_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_0_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_0_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_0_WIN10_TYPES);
			    break;
			case TESTSTAND_4_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_1_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_1_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_1_WIN10_TYPES);
			    break;
			case TESTSTAND_4_2: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_2_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_2_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_2_WIN10_TYPES);
			    break;
			case TESTSTAND_4_21: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_21_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_21_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_21_WIN10_TYPES);
			    break;
			case TESTSTAND_4_5: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_WIN10_TYPES);
			    break;
			case TESTSTAND_4_5_SP1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_4_5_SP1_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_4_5_SP1_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_4_5_SP1_WIN10_TYPES);
			    break;
			case TESTSTAND_5_0: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_0_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_0_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_0_WIN10_TYPES);
			    break;
			case TESTSTAND_5_1: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_5_1_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_5_1_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_5_1_WIN10_TYPES);
			    break;
			case TESTSTAND_14_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_32BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_32BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_32BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_14_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_14_0_64BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_14_0_64BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_14_0_64BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_16_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_32BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_32BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_32BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_16_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_16_0_64BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_16_0_64BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_16_0_64BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_17_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_32BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_32BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_32BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_17_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_17_0_64BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_17_0_64BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_17_0_64BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_19_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_32BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_32BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_32BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_19_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_19_0_64BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_19_0_64BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_19_0_64BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_20_0_32: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_32BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_32BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_32BIT_WIN10_TYPES);
			    break;
			case TESTSTAND_20_0_64: 
				SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, TESTSTAND_20_0_64BIT_WIN10_CONFIG);
			    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, TESTSTAND_20_0_64BIT_WIN10_ICON);
			    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, TESTSTAND_20_0_64BIT_WIN10_TYPES);
			    break;
		}	
	}  else {
		SetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, "");
	    SetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, "");
	    SetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, "");
	}
	
	SetCtrlAttribute (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, ATTR_TEXT_BGCOLOR, VAL_WHITE);
	SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
	SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
	SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			
}


/*int iUpdateRegistrationText( void )
{
   char cName[1024];
   char cCompany[1024];
   char cPhoneNumber[1024];
   char cEMailAdress[1024];
   char cText[10000];
   GetCtrlVal( giRegistrationPanel, REGISTER_NAME, cName );
   GetCtrlVal( giRegistrationPanel, REGISTER_COMPANY, cCompany );
   GetCtrlVal( giRegistrationPanel, REGISTER_PHONE, cPhoneNumber );
   GetCtrlVal( giRegistrationPanel, REGISTER_EMAIL, cEMailAdress );
   sprintf( cText, "Here are my registration informations. Please send me the license files that we have ordered.\n\n" );
   strcat( cText, "Name: " );
   strcat( cText, cName );
   strcat( cText, "\nCompany: " );
   strcat( cText, cCompany );
   strcat( cText, "\nPhone number: " );
   strcat( cText, cPhoneNumber );
   strcat( cText, "\nE-mail adress: " );
   strcat( cText, cEMailAdress );
   strcat( cText, "\nSystem ID: " );
   strcat( cText, gcSystemID );
   strcat( cText, "\nHarddisc ID: " );
   strcat( cText, gcHardDiscID );
   ResetTextBox( giRegistrationPanel, REGISTER_TEXTBOX, cText );
   return 0;
} */


int iCopySWITSFile (char *cSourcePath, char *cDestinationPath, char *FileName, int iMakeBackups, int   iType){
	
	char Source[1024];
	char Target[1024];
	char Backup[1024];
	char Temp[1024];
	char Extension[4];
	char *Date;
	char *Time;
	
	int iLength;
	int iSize;
	int iExists;
	int iError; 
	
	int iVersion;
	
	GetCtrlVal (iMainPanelHandle, PANEL_VERSION, &iVersion);
	
	switch (iType)
	{
		case 0: sprintf(Source, "%sTeststand\\Cfg\\%s", cSourcePath, FileName); break;
		case 1: sprintf(Source, "%sTeststand\\Icons\\%s", cSourcePath, FileName); break;
		case 2: if (iVersion > 9)
				{
					sprintf(Source, "%sTeststand\\TypePalettes\\16\\%s", cSourcePath, FileName); 
				} else {
					sprintf(Source, "%sTeststand\\TypePalettes\\4\\%s", cSourcePath, FileName); 
				}
				break;
		default: return -1;
		
	}
	SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Source);
	SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "\nSetting source -> o.k.\n");    
	
	sprintf(Target, "%s%s", cDestinationPath, FileName);
	SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Target);
	SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "\nSetting target -> o.k.\n");
	
	iExists = FileExists (Target, &iSize);
	if (iExists)
	{
		sprintf(Temp, "Target exists (File size %d bytes!)\n", iSize);
		SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Temp);    	
	}
	if (iMakeBackups && iExists)
	{
		SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Backup must be create.\n");   
		Date = DateStr();
		Time = TimeStr();
		sprintf(Backup, "%s%s", cDestinationPath, FileName);
		iLength = strlen(Backup); 
		Extension[0] = Backup[iLength - 3];
		Extension[1] = Backup[iLength - 2];
		Extension[2] = Backup[iLength - 1];
		Extension[3] = '\0';
		Backup[iLength - 4] = '_';
		Backup[iLength - 3] = Date[6];
		Backup[iLength - 2] = Date[7];
		Backup[iLength - 1] = Date[8];
		Backup[iLength + 0] = Date[9];
        Backup[iLength + 1] = Date[3];
		Backup[iLength + 2] = Date[4];
		Backup[iLength + 3] = Date[0];
		Backup[iLength + 4] = Date[1];
		Backup[iLength + 5] = '_';    
		Backup[iLength + 6] = Time[0];
		Backup[iLength + 7] = Time[1];
		Backup[iLength + 8] = Time[3];
		Backup[iLength + 9] = Time[4];
		Backup[iLength + 10] = Time[6];
		Backup[iLength + 11] = Time[7];
		Backup[iLength + 12] = '.';   
		Backup[iLength + 13] = Extension[0];
		Backup[iLength + 14] = Extension[1];
		Backup[iLength + 15] = Extension[2];
		Backup[iLength + 16] = '\0';
		SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Backup);
	    SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "\nSetting backup -> o.k.\n");
	
		iError = CopyFile (Target, Backup);
		if (iError)
		{
			sprintf(Temp, "An error occurred while creating backup! (Code :%d)\n", iError);
		    SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Temp);           
			MessagePopup ("SW-ITS InstallTool", "An error occurred while creating backup!");
			return -1;
		} else {
			SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Create backup -> o.k.\n"); 
		}
	}
	
	iError = CopyFile (Source, Target);
	if (iError)
	{
		sprintf(Temp, "An error occurred while copying file! (Code :%d)\n", iError);
	    SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, Temp);           
		MessagePopup ("SW-ITS InstallTool", "An error occurred while copying file!");
		return -1;  
	} else {
		SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Copy of file -> o.k.\n"); 
	}
	return 0;
}

/*void CheckLicenses (void)
{
	char cTempBuffer[1024];
	int iLicAccepted;
	
	if (!strlen(gcSystemID) && !strlen(gcHardDiscID))
	{
		SetCtrlVal(iMainPanelHandle, PANEL_SYSID, "Not available");
		SetCtrlVal(iMainPanelHandle, PANEL_LICSTATUS, "Not available");  
		SetCtrlAttribute (iMainPanelHandle, PANEL_SAVESYSTEMID, ATTR_DIMMED, 1);
		SetCtrlAttribute (iMainPanelHandle, PANEL_COPYLICFILE, ATTR_DIMMED, 1);   
	} else {
		if (strlen(gcSystemID)) 
		{
			sprintf (cTempBuffer, "System-ID: %s", gcSystemID); 
		} else {
			sprintf (cTempBuffer, "System-ID: n.a."); 
		}
		if (strlen(gcHardDiscID)) 
		{
			strcat (cTempBuffer, ", Harddisc-ID: "); 
			strcat (cTempBuffer, gcHardDiscID);     
		} else {
			sprintf (cTempBuffer, ", Harddisc-ID: n.a."); 
		}
		SetCtrlVal(iMainPanelHandle, PANEL_SYSID, cTempBuffer);
		
		/*iLicAccepted = lc_CheckLicense ("SW-ITS", gcSystemID);
		if (iLicAccepted)
		{
			sprintf (cTempBuffer, "SW-ITS"); 
			 
		} else {
			sprintf (cTempBuffer, ""); 
		}
		
		iLicAccepted = lc_CheckLicense ("AE-ITS", gcHardDiscID);
		if (iLicAccepted)
		{
			if (strlen(cTempBuffer))
			{
				strcat (cTempBuffer, ", AE-ITS (HD)"); 
			} else {
				strcat (cTempBuffer, "AE-ITS (HD)"); 
			}
		}
		
		iLicAccepted = lc_CheckLicense ("CP-ITS", gcHardDiscID);
		if (iLicAccepted)
		{
			if (strlen(cTempBuffer))
			{
				strcat (cTempBuffer, ", CP-ITS (HD)"); 
			} else {
				strcat (cTempBuffer, "CP-ITS (HD)"); 
			}
		}
		
		
		iLicAccepted = lc_CheckLicense ("CC-ITS", gcHardDiscID);
		if (iLicAccepted)
		{
			if (strlen(cTempBuffer))
			{
				strcat (cTempBuffer, ", CC-ITS (HD)"); 
			} else {
				strcat (cTempBuffer, "CC-ITS (HD)"); 
			}
		}
		
		iLicAccepted = lc_CheckLicense ("GDIO-MGR", gcHardDiscID);
		if (iLicAccepted)
		{
			if (strlen(cTempBuffer))
			{
				strcat (cTempBuffer, ", GDIO-MGR (HD)"); 
			} else {
				strcat (cTempBuffer, "GDIO-MGR (HD)"); 
			}
		}  
		
		if(!strlen(cTempBuffer)) sprintf (cTempBuffer, "No licenses found");
		SetCtrlVal(iMainPanelHandle, PANEL_LICSTATUS, cTempBuffer); 
	}

}
	 */ 
	
	
int main (int argc, char *argv[])
{
	
	char cDriveName[1024];
    char cDirectory[1024];
    char cFileName[1024];
    short sErrorOccured;
	int   iErroCode;
	char  cErrorMessage[1024];
	char cProjectDir[1024];
	
	CA_InitActiveXThreadStyleForCurrentThread (0, COINIT_APARTMENTTHREADED);        
	
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((iMainPanelHandle = LoadPanel (0, "InstallTool.uir", PANEL)) < 0)
		return -1;
	
	if ((iMeDriverPanelHandle = LoadPanel (0, "InstallTool.uir", MEDRIVER)) < 0)
		return -1;
	
	if ((iLogPanelHandle = LoadPanel (0, "InstallTool.uir", PANEL_2)) < 0)
		return -1; 
	
	if ((iSplashPanelHandle = LoadPanel (0, "Splash.uir", SPLASH)) < 0)
		return -1; 
	
	/*if ((giRegistrationPanel = LoadPanel (0, "InstallTool.uir", REGISTER)) < 0)
		return -1; 		*/
	
	if ((iBackupPanelHandle = LoadPanel (0, "InstallTool.uir", CREATEBACK)) < 0)
		return -1; 
	
	iMenuBarHandle = GetPanelMenuBar (iMainPanelHandle);
	
	GetProjectDir(cProjectDir);
	cProjectDir[strlen(cProjectDir) - 3] = '\0';
    
	SetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cProjectDir);    
	
	if (!stricmp (cProjectDir, SWITS_XP_GER))
	{
		SetCtrlVal(iMainPanelHandle, PANEL_LANGUAGE, XP_GERMAN); 
	} else if (!stricmp (cProjectDir, SWITS_XP_ENG))  
	{
		SetCtrlVal(iMainPanelHandle, PANEL_LANGUAGE, XP_ENGLISH); 
	}  else if (!stricmp (cProjectDir, SWITS_WIN_7))  
	{
		SetCtrlVal(iMainPanelHandle, PANEL_LANGUAGE, WIN_7); 
	} else if (!stricmp (cProjectDir, SWITS_WIN_8))  
	{
		SetCtrlVal(iMainPanelHandle, PANEL_LANGUAGE, WIN_8); 
	}  else if (!stricmp (cProjectDir, SWITS_WIN_10))  
	{
		SetCtrlVal(iMainPanelHandle, PANEL_LANGUAGE, WIN_10); 
	} 
	
	
	
	///////////////////////////////////////////////////////
	// Get hard disc ID
	///////////////////////////////////////////////////////
	GetProjectDir(cProjectDir);
	cProjectDir[strlen(cProjectDir) - 3] = '\0';
	SplitPath( cProjectDir, cDriveName, cDirectory, cFileName );
    strcat( cDriveName, "\\" );
	
	//Allocate the necessary memory
    /*lpVolumeNameBuffer = malloc( 256 );
    lpFileSystemNameBuffer = malloc( 256 );
    error = GetVolumeInformation( cDriveName,  // root directory
    lpVolumeNameBuffer,  // volume name buffer
    256,  // length of name buffer
    &lpVolumeSerialNumber,  // volume serial number
    &lpMaximumComponentLength,  // maximum file name length
    &lpFileSystemFlags,  // file system options
    lpFileSystemNameBuffer,  // file system name buffer
    256 );
    if ( lpVolumeSerialNumber != 0 )
    {
       sprintf(gcHardDiscID, "0x%X", lpVolumeSerialNumber );
    }
	free(lpVolumeNameBuffer);
	free(lpFileSystemNameBuffer);  */
   
    ///////////////////////////////////////////////////////
	// Get TSVP System ID
	///////////////////////////////////////////////////////
	/*sprintf(gcSystemID,"");
	RESMGR_Setup (0, "", "", &sErrorOccured, &iErroCode, cErrorMessage);
	RESMGR_Read_ROM (0, gcSystemID, &sErrorOccured, &iErroCode, cErrorMessage);
	RESMGR_Cleanup (0, &sErrorOccured, &iErroCode, cErrorMessage); 
	
	CheckLicenses ();	   */
	
	DisplayPanel (iMainPanelHandle);
	
	RunUserInterface ();
	
	DiscardPanel (iMainPanelHandle);
	DiscardPanel (iLogPanelHandle); 
	DiscardPanel (iSplashPanelHandle); 
	//DiscardPanel (giRegistrationPanel); 
	DiscardPanel (iMeDriverPanelHandle);      
	DiscardPanel (iBackupPanelHandle);      
	
	return 0;
}

int CVICALLBACK MainPanelCallBack (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK CreateBackupPanelCallback (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			RemovePopup (panel);
			break;
	}
	return 0;
}


int CVICALLBACK SelectConfigFolder (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			iFoldersModified++;
			GetCtrlVal (iMainPanelHandle, PANEL_CONFIGFILES, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				SetCtrlVal (iMainPanelHandle, PANEL_ICONFILES, cSelectedPath);  
				SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectIconFolder (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			iFoldersModified++;
			GetCtrlVal (iMainPanelHandle, PANEL_ICONFILES, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				SetCtrlVal (iMainPanelHandle, PANEL_ICONFILES, cSelectedPath);  
				SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectTypePaletteFolder (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			iFoldersModified++;
			GetCtrlVal (iMainPanelHandle, PANEL_TYPEPALETTES, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				SetCtrlVal (iMainPanelHandle, PANEL_TYPEPALETTES, cSelectedPath);  
				SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			}
			break;
	}
	return 0;
}

int CVICALLBACK ModifyFolders (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iActualVersion;
	int iActualLanguage;  
	int iModifyFolders;
	int iConfirm;
	switch (event)
	{
		case EVENT_COMMIT:
			 GetCtrlVal (iMainPanelHandle, control, &iModifyFolders);
			
			 if (!iModifyFolders && iFoldersModified)
			 {
				 iConfirm = ConfirmPopup ("SW-ITS InstallTool", "You have changed the settings of the directories. If you continue, these settings are lost. Do you want to continue?"); 
				 if (!iConfirm) return 0;
			 }
			 
			 SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_DIMMED, !iModifyFolders);
		     SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALSELBUTTON, ATTR_DIMMED, !iModifyFolders);
		     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_DIMMED, !iModifyFolders);
		     SetCtrlAttribute (iMainPanelHandle, PANEL_ICONSELBUTTON, ATTR_DIMMED, !iModifyFolders);
		     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_DIMMED, !iModifyFolders);
		     SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGSELBUTTON, ATTR_DIMMED, !iModifyFolders);
			 
			 if (iFoldersModified)
			 {
				 iFoldersModified = 0;
				 GetCtrlVal (iMainPanelHandle, PANEL_VERSION, &iActualVersion);
				 GetCtrlVal (iMainPanelHandle, PANEL_LANGUAGE, &iActualLanguage);
				 SetFiles (iActualVersion, iActualLanguage);
			 }
			
			 break;
	}
	return 0;
}

int CVICALLBACK CopyFiles (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char cPath[1024];
	char cSourcePath[1024];
	char cDestinationPath[1024];
	char cFile[1024];
	int iCopyCfgFiles, iMakeBackups, iConfirm;   
	int iError;
	int iErrorSum;
	int iFileExists;
	int iSize;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iMainPanelHandle, PANEL_COPYCFGFILE, &iCopyCfgFiles);  
			GetCtrlVal (iMainPanelHandle, PANEL_CREATEBACKUP, &iMakeBackups);  
			
			if (!iMakeBackups )
			{
				iConfirm = ConfirmPopup ("SW-ITS InstallTool", "You have disabled the create backup option.\n\nWe strongly recommend to create backups of all NI ini-files!\n\nDo you wish to continue?"); 
				 if (!iConfirm) return 0;	
			}
			
			ResetTextBox (iLogPanelHandle, PANEL_2_TEXTBOX, "");
			
			SetCtrlAttribute (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			//Check folders
			iErrorSum = 0;
			GetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cPath);
			iError = SetDir (cPath);
			if (iError) {
				iErrorSum++;
				SetCtrlAttribute (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, ATTR_TEXT_BGCOLOR, VAL_RED);
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check SW-ITS install directory -> not found\n");
			} else {
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check SW-ITS install directory -> o.k.\n");
			}
			GetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, cPath);
			iError = SetDir (cPath);
			if (iError) {
				iErrorSum++;
				SetCtrlAttribute (iMainPanelHandle, PANEL_CONFIGFILES, ATTR_TEXT_BGCOLOR, VAL_RED);
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for configuration files -> not found\n");  
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for configuration files -> o.k.\n");  
			}
			GetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, cPath);
			iError = SetDir (cPath);
			if (iError) {
				iErrorSum++;
				SetCtrlAttribute (iMainPanelHandle, PANEL_ICONFILES, ATTR_TEXT_BGCOLOR, VAL_RED);           
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for icon files -> not found\n");  
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for icon files -> o.k.\n");  
			}
			GetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, cPath);
			iError = SetDir (cPath);    
			if (iError) {
				iErrorSum++;
				SetCtrlAttribute (iMainPanelHandle, PANEL_TYPEPALETTES, ATTR_TEXT_BGCOLOR, VAL_RED);  
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for type palette files -> not found\n");       
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check target directory for type palette files -> o.k.\n");       
			}
			if (iErrorSum)
			{
				MessagePopup ("SW-ITS InstallTool", "One or more of the specified paths was not found..");
				SetCtrlAttribute (iMainPanelHandle, PANEL_SHOWLOG, ATTR_DIMMED, 0);
				return 0;
			}
			iErrorSum = 0;
			//Check files
			GetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cPath);  
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			sprintf (cFile, "%sTeststand\\Cfg\\StationGlobals.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file StationGlobals.ini -> not found\n");       
			
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file StationGlobals.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Cfg\\Templates.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file Templates.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file Templates.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Cfg\\TestExec.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file TestExec.ini -> not found\n");   
			}  else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file TestExec.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Cfg\\ToolMenu.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ToolMenu.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ToolMenu.ini -> o.k.\n");
			}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			sprintf (cFile, "%sTeststand\\Icons\\rs.ico", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rs.ico -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rs.ico -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Icons\\step.ico", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral.ico -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral.ico -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Icons\\teststep.ico", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral_test.ico -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral_test.ico -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\Icons\\goepel.ico", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral_test.ico -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file spectral_test.ico -> o.k.\n");
			}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\audioanl_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file audioanl_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file audioanl_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\dcpwr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dcpwr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dcpwr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\diomgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file diomgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file diomgr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\dmm_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dmm_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dmm_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\finfix_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file finfix_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file finfix_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\funcgen_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file funcgen_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file funcgen_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\goepel_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file goepel_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file goepel_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\goepel_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ict_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ict_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\resmgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file resmgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file resmgr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\route_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file route_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file route_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\rspio2_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rspio2_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rspio2_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\siganl_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file siganl_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file siganl_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\standard_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file standard_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file standard_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\swmgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file swmgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file swmgr_library.inii -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\user_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file user_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file user_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\4\\vacuum_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file vacuum_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file vacuum_library.ini -> o.k.\n");
			}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\audioanl_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file audioanl_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file audioanl_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\dcpwr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dcpwr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dcpwr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\diomgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file diomgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file diomgr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\dmm_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dmm_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file dmm_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\finfix_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file finfix_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file finfix_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\funcgen_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file funcgen_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file funcgen_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\goepel_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file goepel_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file goepel_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\goepel_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ict_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file ict_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\resmgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file resmgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file resmgr_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\route_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file route_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file route_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\rspio2_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;	
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rspio2_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file rspio2_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\siganl_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file siganl_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file siganl_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\standard_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file standard_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file standard_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\swmgr_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file swmgr_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file swmgr_library.inii -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\user_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file user_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file user_library.ini -> o.k.\n");
			}
			sprintf (cFile, "%sTeststand\\TypePalettes\\16\\vacuum_library.ini", cPath);
			iError = FileExists(cFile, &iSize);
			if (!iError)
			{
				iErrorSum++;
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file vacuum_library.ini -> not found\n");   
			} else { 
				SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "Check source file vacuum_library.ini -> o.k.\n");
			}
			if (iErrorSum)
			{
				MessagePopup ("SW-ITS InstallTool", "One or more of the required files were not found. Please check the installation directory.");
				SetCtrlAttribute (iMainPanelHandle, PANEL_SHOWLOG, ATTR_DIMMED, 0);
				return 0;
			}
			
			GetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cSourcePath);
		    GetCtrlVal(iMainPanelHandle, PANEL_CONFIGFILES, cDestinationPath);
		
			if (iCopyCfgFiles)
			{
				iError = iCopySWITSFile (cSourcePath, cDestinationPath, "StationGlobals.ini", iMakeBackups, 0);
				if (iError) goto ERRORTAG;
				iError = iCopySWITSFile (cSourcePath, cDestinationPath, "Templates.ini", iMakeBackups, 0); 
				if (iError) goto ERRORTAG;
				iError = iCopySWITSFile (cSourcePath, cDestinationPath, "TestExec.ini", iMakeBackups, 0); 
				if (iError) goto ERRORTAG;
				iError = iCopySWITSFile (cSourcePath, cDestinationPath, "ToolMenu.ini", iMakeBackups, 0); 
				if (iError) goto ERRORTAG;
			}
		
			GetCtrlVal(iMainPanelHandle, PANEL_ICONFILES, cDestinationPath);
		
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "rs.ico", 0, 1);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "step.ico", 0, 1);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "teststep.ico", 0, 1);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "goepel.ico", 0, 1);
			if (iError) goto ERRORTAG;
			
			GetCtrlVal(iMainPanelHandle, PANEL_TYPEPALETTES, cDestinationPath);
		
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "audioanl_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "dcpwr_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "diomgr_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "dmm_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "finfix_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "funcgen_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "goepel_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "ict_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "resmgr_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "route_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "rspio2_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "siganl_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "standard_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "swmgr_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "user_library.ini", iMakeBackups, 2);
			if (iError) goto ERRORTAG;
			iError = iCopySWITSFile (cSourcePath, cDestinationPath, "vacuum_library.ini", 0, 2);
			if (iError) goto ERRORTAG;
			
			SetCtrlVal (iLogPanelHandle,PANEL_2_TEXTBOX, "\nCopy process finished without errors.\n\n");
			
			MessagePopup("SW-ITS InstallTool", "All files have been copied to your suitable position."); 
			
ERRORTAG:
			
			SetCtrlAttribute (iMainPanelHandle, PANEL_SHOWLOG, ATTR_DIMMED, 0); 
			
			break;
	}
	
	
	
	return 0;
}

int CVICALLBACK VersionSelected (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iConfirm;
	int iActualVersion;
	int iActualLanguage;  
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			if (iFoldersModified)
			{
				 iConfirm = ConfirmPopup ("SW-ITS InstallTool", "You have changed the settings of the directories. If you continue, these settings are lost. Do you want to continue?"); 
				 if (!iConfirm) return 0;
			}
			GetCtrlVal (iMainPanelHandle, PANEL_VERSION, &iActualVersion);
			GetCtrlVal (iMainPanelHandle, PANEL_LANGUAGE, &iActualLanguage);
			SetFiles (iActualVersion, iActualLanguage);
			break;
	}
	return 0;
}

int CVICALLBACK LanguageSelected (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iConfirm;
	int iActualVersion;
	int iActualLanguage;  
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			if (iFoldersModified)
			{
				 iConfirm = ConfirmPopup ("SW-ITS InstallTool", "You have changed the settings of the directories. If you continue, these settings are lost. Do you want to continue?"); 
				 if (!iConfirm) return 0;
			}
			GetCtrlVal (iMainPanelHandle, PANEL_VERSION, &iActualVersion);
			GetCtrlVal (iMainPanelHandle, PANEL_LANGUAGE, &iActualLanguage);
			SetFiles (iActualVersion, iActualLanguage);
			break;
	}
	return 0;
}

int CVICALLBACK FoldersModified (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			iFoldersModified++;
			break;
	}
	return 0;
}

int CVICALLBACK SWITSInstallFolderModified (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			break;
	}
	return 0;
}

int CVICALLBACK SelectInstallFolder (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cSelectedPath);     
				SetCtrlAttribute (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, ATTR_TEXT_BGCOLOR, VAL_WHITE);
			}
			break;
	}
	return 0;
}

int CVICALLBACK ShowLog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			InstallPopup (iLogPanelHandle);
			break;
	}
	return 0;
}

int CVICALLBACK CloseLogFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RemovePopup (iLogPanelHandle);
			break;
	}
	return 0;
}

int CVICALLBACK SaveLogFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	int iSelStatus, iCountOfLines, idx;
	char cProjectDir[1024];
	char cPathName[1024];
	char cBuffer[1024];
    FILE *pFile;
	switch (event)
	{
		case EVENT_COMMIT:
			GetProjectDir(cProjectDir);
			iSelStatus = FileSelectPopup (cProjectDir, "*.log", "", "Specify path and file name", VAL_SAVE_BUTTON, 0, 1, 1, 1, cPathName);
			if (iSelStatus){
				pFile = fopen(cPathName, "w");
				fprintf(pFile, "\nSW-ITS Install wizzard log file.\n", cBuffer);
				fprintf(pFile, "Created: %s %s\n\n", DateStr(), TimeStr());
				if (errno) return 0;
				GetNumTextBoxLines (iLogPanelHandle, PANEL_2_TEXTBOX, &iCountOfLines);
				for (idx = 0; idx < iCountOfLines; idx++)
			    {
					GetTextBoxLine (iLogPanelHandle, PANEL_2_TEXTBOX, idx, cBuffer);
					fprintf(pFile, "%s\n", cBuffer);
					if (errno) return 0;
				}
				fclose(pFile);
			}
			break;
	}
	return 0;
}

int CVICALLBACK SaveSystemID (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iSelStatus, iCharsWritten;
	FILE *pFile;
	char cProjectDir[1024];
	char cPathName[1024];
	
	switch (event)
	{
		case EVENT_COMMIT:
			/*
		    GetProjectDir(cProjectDir);
			iSelStatus = FileSelectPopup (cProjectDir, "System-ID-TSVP.txt", "", "Specify path and file name", VAL_SAVE_BUTTON, 0, 1, 1, 1, cPathName);
			if (iSelStatus){
				pFile = fopen(cPathName, "w");
				if (!pFile) return 0;
				iCharsWritten = fprintf (pFile, "\nSW-ITS Install Tool\n\n");
				if (!iCharsWritten) return 0;
				iCharsWritten = fprintf(pFile, "Created: %s %s\n\n", DateStr(), TimeStr());
				if (!iCharsWritten) return 0;      
				iCharsWritten = fprintf(pFile, "System-ID: %s\n", gcSystemID);
				if (!iCharsWritten) return 0;      
				fclose(pFile);
				MessagePopup("SW-ITS InstallTool", "Send this file to sw-its@spectral-electronic.de!");
			}
		*/
			InstallPopup(giRegistrationPanel);
			break;
	}
	return 0;
}

void CVICALLBACK ExitProgram (int menuBar, int menuItem, void *callbackData,
		int panel)
{
 	QuitUserInterface (0);  
}

void CVICALLBACK AboutProgram (int menuBar, int menuItem, void *callbackData,
		int panel)
{
   char cTextMessage[1024];
   sprintf( cTextMessage, "SW-ITS InstallTool - Version %s ", VERSION );
   SetCtrlVal( iSplashPanelHandle, SPLASH_SELECTEDSEQ, cTextMessage );
   SetCtrlAttribute( iSplashPanelHandle, SPLASH_SELECTEDSEQ, ATTR_TEXT_BGCOLOR, VAL_TRANSPARENT );
   SetCtrlAttribute( iSplashPanelHandle, SPLASH_LABEL, ATTR_TEXT_BGCOLOR, VAL_TRANSPARENT );
   SetCtrlAttribute( iSplashPanelHandle, SPLASH_PRODUCT, ATTR_TEXT_BGCOLOR, VAL_TRANSPARENT );
   DisplayPanel (iSplashPanelHandle);
}

int CVICALLBACK PictureCallBack (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_LEFT_CLICK: 
			               HidePanel (iSplashPanelHandle); 
		                   break;
	}
	return 0;
}

int CVICALLBACK SlpashCallBack (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT: HidePanel (iSplashPanelHandle); 

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:

			break;
	}
	return 0;
}



/*int CVICALLBACK CopyLicenseFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iSelStatus, iError, iLicAccepted;
	FILE *pFile;
	char cProjectDir[1024];
	char cSourcePathName[1024];
	char cTargetPathName[1024];
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetProjectDir(cProjectDir);
			iSelStatus = FileSelectPopup (cProjectDir, "*.lic", "", "Specify path and file name", VAL_SELECT_BUTTON, 0, 1, 1, 0, cSourcePathName);
			if (iSelStatus == 1)
			{
				GetCtrlVal (iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cTargetPathName);
				strcat (cTargetPathName, "License\\");
				strcat (cTargetPathName, gcSystemID);
				strcat (cTargetPathName, "\\");
				iError = MakeDir (cTargetPathName);
				if (iError)
				{
					MessagePopup("SW-ITS InstallTool", "Could not create directory for .lic file in license directory.");	
					return 0;
				}
				strcat (cTargetPathName, "SW-ITS.lic");
				iError = CopyFile (cSourcePathName, cTargetPathName);
				if (iError)
				{
					MessagePopup("SW-ITS InstallTool", "Could not copy file .lic file in license directory.");	
					return 0;
				}
				
				CheckLicenses ();
	
			}
			break;
	}
	return 0;
}

int CVICALLBACK CopyTextToClipBoard( int panel, int control, int event, void *callbackData, int eventData1, int eventData2 )
{
   int iTextLength;
   char *cTextBoxValue;
   switch ( event )
   {
      case EVENT_COMMIT:
         GetCtrlAttribute( giRegistrationPanel, REGISTER_TEXTBOX, ATTR_STRING_TEXT_LENGTH, &iTextLength );
         cTextBoxValue = malloc( sizeof( char )*( iTextLength + 1 ));
         GetCtrlVal( giRegistrationPanel, REGISTER_TEXTBOX, cTextBoxValue );
         ClipboardPutText( cTextBoxValue );
         free( cTextBoxValue );
         break;
   }
   return 0;
}

int CVICALLBACK CloseRegisterPanel( int panel, int control, int event, void *callbackData, int eventData1, int eventData2 )
{
   switch ( event )
   {
      case EVENT_COMMIT:
         RemovePopup( giRegistrationPanel );
         break;
   }
   return 0;
}

int CVICALLBACK RegisterPanelCallback( int panel, int event, void *callbackData, int eventData1, int eventData2 )
{
   switch ( event )
   {
      case EVENT_GOT_FOCUS:
         break;
      case EVENT_LOST_FOCUS:
         break;
      case EVENT_CLOSE:
         RemovePopup( giRegistrationPanel );
         break;
   }
   return 0;
}		

int CVICALLBACK RegistrationValueChanged( int panel, int control, int event, void *callbackData, int eventData1, int eventData2 )
{
   switch ( event )
   {
      case EVENT_VAL_CHANGED:
         iUpdateRegistrationText();
         break;
   }
   return 0;
}	 */ 

int CVICALLBACK ChangeMEDriver (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iVal;
	
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			GetCtrlVal(panel, control, &iVal);
			if (iVal > 0) SetCtrlAttribute (panel, MEDRIVER_APPLY, ATTR_DIMMED, 0);
			if (iVal < 0) SetCtrlAttribute (panel, MEDRIVER_APPLY, ATTR_DIMMED, 1);
			break;
	}
	return 0;
}

int CVICALLBACK ApplyDriver (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iVal, iResult;
	char cSeqPath[1024];
	char cDelPath[1024];
	char cSelVersPath[1024];
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(iMeDriverPanelHandle, MEDRIVER_MESWITCH, &iVal);
			GetCtrlVal(iMainPanelHandle, PANEL_SWITSINSTALLFOLDER, cSeqPath); 
			strcat(cSeqPath, "Sequences\\" );
			sprintf(cDelPath, cSeqPath);
			sprintf(cSelVersPath, cSeqPath);
			
			if (iVal == 1)
			{
				strcat(cDelPath, "LTE_Library.seq" );
				strcat(cSelVersPath, "LTE_Library_WDM_Version.seq" );
				iResult = DeleteFile (cDelPath);
				if (iResult)
				{
					MessagePopup("SW-ITS InstallTool", "Could not delete old LTE Library");
					return 0;
				}
				iResult = CopyFile(cSelVersPath, cDelPath);
				if (iResult)
				{
					MessagePopup("SW-ITS InstallTool", "Could not copy new LTE Library");
					return 0;
				}
			} else if (iVal == 2) 
			{
				strcat(cDelPath, "LTE_Library.seq" );
				strcat(cSelVersPath, "LTE_Library_ME_iDS_Version.seq" );
				iResult = DeleteFile (cDelPath);
				if (iResult)
				{
					MessagePopup("SW-ITS InstallTool", "Could not delete old LTE Library");
					return 0;
				}
				iResult = CopyFile(cSelVersPath, cDelPath);
				if (iResult)
				{
					MessagePopup("SW-ITS InstallTool", "Could not copy new LTE Library");
					return 0;
				}
				
			}
			RemovePopup (iMeDriverPanelHandle);    
			break;
	}
	return 0;
}

int CVICALLBACK CancelDriver (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RemovePopup (iMeDriverPanelHandle);         
			break;
	}
	return 0;
}

void CVICALLBACK ChangeME (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	InstallPopup (iMeDriverPanelHandle);
}

void CVICALLBACK CreateRoboCopyBackUpScript (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	
	iBatchFileIsSet = 0;
	iLogFileIsSet = 0;
	iBackupPathIsSet = 0;
	InstallPopup (iBackupPanelHandle);
}

int CVICALLBACK FoldersModifiedBackup (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK SelectBatchFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char cDefaultFilePath[1024];
	char cFilePath[1024];
	char cFilePathOrigin[1024];
	int iStatus;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_BATCH, cFilePathOrigin);   
			if(strlen(cFilePathOrigin))
			{
				sprintf(cDefaultFilePath, cFilePathOrigin);
			} else {
				sprintf(cDefaultFilePath, "C:\\Users\\Public\\Documents\\SW-ITS");
			}
			iStatus = FileSelectPopup (cDefaultFilePath, "*.bat", "", "Select path and file name of batch file", VAL_SAVE_BUTTON, 0, 1, 1, 1, cFilePath);
			if (iStatus <= 0) return 0;
			SetCtrlVal (iBackupPanelHandle, CREATEBACK_BATCH, cFilePath);
			iBatchFileIsSet = 1;
			if (iBatchFileIsSet && iLogFileIsSet && iBackupPathIsSet) SetCtrlAttribute (panel, CREATEBACK_SAVE, ATTR_DIMMED, 0);
			break;
	}
	return 0;
}

int CVICALLBACK SelectLogFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char cDefaultFilePath[1024];
	char cLogFilePath[1024];
	char cLogFilePathOrigin[1024];
	int iStatus;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_LOG, cLogFilePathOrigin);   
			if(strlen(cLogFilePathOrigin))
			{
				sprintf(cDefaultFilePath, cLogFilePathOrigin);
			} else {
				sprintf(cDefaultFilePath, "C:\\Users\\Public\\Documents\\SW-ITS");
			}
			iStatus = FileSelectPopup (cDefaultFilePath, "*.log", "", "Select path and file name of robocopy log file", VAL_SAVE_BUTTON, 0, 1, 1, 1, cLogFilePath);
			if (iStatus <= 0) return 0;
			SetCtrlVal (iBackupPanelHandle, CREATEBACK_LOG, cLogFilePath);
			iLogFileIsSet = 1;
			if (iBatchFileIsSet && iLogFileIsSet && iBackupPathIsSet) SetCtrlAttribute (panel, CREATEBACK_SAVE, ATTR_DIMMED, 0);
			break;
	}
	return 0;
}

int CVICALLBACK SelectBackupPath (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char cDefaultFilePath[1024];
	char cBackupPath[1024];
	char cBackupPathOrigin[1024];
	int iStatus;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_BACKUPPATH, cBackupPathOrigin);   
			if(strlen(cBackupPathOrigin))
			{
				sprintf(cDefaultFilePath, cBackupPathOrigin);
			} else {
				sprintf(cDefaultFilePath, "C:\\Users\\Public\\Documents\\SW-ITS");
			}
			iStatus = DirSelectPopup (cDefaultFilePath, "Select backup directory", "", 1, cBackupPath);
			if (iStatus <= 0) return 0;
			SetCtrlVal (iBackupPanelHandle, CREATEBACK_BACKUPPATH, cBackupPath);
			iBackupPathIsSet = 1;
			if (iBatchFileIsSet && iLogFileIsSet && iBackupPathIsSet) SetCtrlAttribute (panel, CREATEBACK_SAVE, ATTR_DIMMED, 0);
			break;
	}
	return 0;
}

int CVICALLBACK SelectRSProg (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_RS, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select R&S program Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_RS, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectRSDoc (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_RS_2, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select R&S documents Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_RS_2, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectSWProg (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select SW-ITS program Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectSWDoc (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS_2, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select SW-ITS documents Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS_2, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectNIDoc (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_NI, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select NI documents Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_NI, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SelectNICfg (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus;
	char cDefaultPath[1024];
	char cSelectedPath[1024];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_NI_2, cDefaultPath);       
			iStatus = DirSelectPopup (cDefaultPath, "Select NI configuration Directory", 1, 0, cSelectedPath);
			if (iStatus)
			{
				strcat(cSelectedPath, "\\");
				SetCtrlVal (iBackupPanelHandle, CREATEBACK_NI_2, cSelectedPath);     
			}
			break;
	}
	return 0;
}

int CVICALLBACK SaveBatchFile (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int iStatus, iConfirm;
	
	char cBatchFilePath[1024];
	char cLogFilePath[1024];
	char cBackupPath[1024];
	
	char cRSProgramPath[1024];
	char cRSDocPath[1024];
	char cSWITSProgramPath[1024];
	char cSWITSDocPath[1024];
	char cNIDocPath[1024];
	char cNICfgPath[1024];
	
	char cTempDrive[1024];
	char cTempDir[1024];
	char cTempFile[1024];
	char cPathWithoutDrive[1024]; 
	
	
	FILE *pFile;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_BATCH, cBatchFilePath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_LOG, cLogFilePath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_BACKUPPATH, cBackupPath);    
			
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_RS, cRSProgramPath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_RS_2, cRSDocPath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS, cSWITSProgramPath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_SWITS_2, cSWITSDocPath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_NI, cNIDocPath);    
			GetCtrlVal (iBackupPanelHandle, CREATEBACK_NI_2, cNICfgPath);    
				
			pFile = fopen(cBatchFilePath, "w");
			if(!pFile)
			{
				MessagePopup ("InstallTool", "Cannot create batch file.");
				return 0;
			}
			
			fprintf(pFile, "cls\n");
			fprintf(pFile, "@echo off\n\n");
			fprintf(pFile, "rem Created by: SW-ITS InstallTool (Version %s)\n", VERSION);
			fprintf(pFile, "rem Created on: %s - %s\n\n", DateStr(), TimeStr());
			fprintf(pFile, "rem --------This is the RoboCopy command that will be executed:-----------\n");
	
			SplitPath(cRSProgramPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cRSProgramPath[strlen(cRSProgramPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of programs folder Rohde-Schwarz. Please wait...\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cRSProgramPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
	
			SplitPath(cRSDocPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cRSDocPath[strlen(cRSDocPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of documents folder Rohde-Schwarz. Please wait...\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cRSDocPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
	
			SplitPath(cSWITSProgramPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cSWITSProgramPath[strlen(cSWITSProgramPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of programs folder SW-ITS. Please wait...\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cSWITSProgramPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
	
			SplitPath(cSWITSDocPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cSWITSDocPath[strlen(cSWITSDocPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of documents folder SW-ITS. Please wait...\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cSWITSDocPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
	
			SplitPath(cNIDocPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cNIDocPath[strlen(cNIDocPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of documents folder National Instruments. Please wait...\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cNIDocPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
	
			SplitPath(cNICfgPath, cTempDrive, cPathWithoutDrive, cTempFile);
			cNICfgPath[strlen(cNICfgPath)-1] = '\0';
			cPathWithoutDrive[strlen(cPathWithoutDrive)-1] = '\0';
			fprintf(pFile, "echo Create backup of config folder National Instruments. Please wait...\n\n");
			fprintf(pFile, "START /wait robocopy \"%s\" \"%s%s\" /mir /LOG+:%s\n", cNICfgPath, cBackupPath, cPathWithoutDrive, cLogFilePath);
			
			fprintf(pFile, "rem -----------------------------------------------------------------------\n"); 
			fprintf(pFile, "rem The following commands will be executed after the copy and will append the log file.\n\n"); 

			fprintf(pFile, "echo.    >> \"%s\"\n", cLogFilePath); 
			fprintf(pFile, "echo     Machine ID   - %%computername%% >> \"%s\"\n", cLogFilePath); 
			fprintf(pFile, "echo     Account      - %%username%% >> \"%s\"\n", cLogFilePath); 
			fprintf(pFile, "echo.    >> \"%s\"\n", cLogFilePath); 
			fprintf(pFile, "echo     ######################################################################################### >> \"%s\"\n\n", cLogFilePath); 
			
			fprintf(pFile, "pause\n\n"); 

			fclose (pFile);
			
			iConfirm = ConfirmPopup("SW-ITS", "Batch file successfully created. Would you run the batch file now?");
			if(iConfirm) LaunchExecutable (cBatchFilePath);
			
			RemovePopup(iBackupPanelHandle);
			
			break;
	}
	return 0;
}

int CVICALLBACK CloseBackupPanel (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RemovePopup (iBackupPanelHandle); 
			break;
	}
	return 0;
}
