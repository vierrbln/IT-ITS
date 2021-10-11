/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  CREATEBACK                       1       /* callback function: CreateBackupPanelCallback */
#define  CREATEBACK_BACKUPPATH            2       /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_BACKUPPATH_BUTTON     3       /* control type: command, callback function: SelectBackupPath */
#define  CREATEBACK_LOG                   4       /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_LOGFILE_BUTTON        5       /* control type: command, callback function: SelectLogFile */
#define  CREATEBACK_SAVE                  6       /* control type: command, callback function: SaveBatchFile */
#define  CREATEBACK_CLOSE_2               7       /* control type: command, callback function: CloseBackupPanel */
#define  CREATEBACK_NI_2                  8       /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_SWITS_2               9       /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_NI                    10      /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_NI_CFG_BUTTON         11      /* control type: command, callback function: SelectNICfg */
#define  CREATEBACK_SW_DOC_BUTTON         12      /* control type: command, callback function: SelectSWDoc */
#define  CREATEBACK_NI_DOC_BUTTON         13      /* control type: command, callback function: SelectNIDoc */
#define  CREATEBACK_SWITS                 14      /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_SW_PROG_BUTTON        15      /* control type: command, callback function: SelectSWProg */
#define  CREATEBACK_RS_2                  16      /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_RS_DOC_BUTTON         17      /* control type: command, callback function: SelectRSDoc */
#define  CREATEBACK_RS                    18      /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_RS_PROG_BUTTON        19      /* control type: command, callback function: SelectRSProg */
#define  CREATEBACK_BATCH                 20      /* control type: string, callback function: FoldersModifiedBackup */
#define  CREATEBACK_BATCHFILE_BUTTON      21      /* control type: command, callback function: SelectBatchFile */
#define  CREATEBACK_DECORATION            22      /* control type: deco, callback function: (none) */
#define  CREATEBACK_DECORATION_2          23      /* control type: deco, callback function: (none) */

#define  MEDRIVER                         2
#define  MEDRIVER_MESWITCH                2       /* control type: ring, callback function: ChangeMEDriver */
#define  MEDRIVER_CANCEL                  3       /* control type: command, callback function: CancelDriver */
#define  MEDRIVER_APPLY                   4       /* control type: command, callback function: ApplyDriver */

#define  PANEL                            3       /* callback function: MainPanelCallBack */
#define  PANEL_VERSION                    2       /* control type: ring, callback function: VersionSelected */
#define  PANEL_COPY                       3       /* control type: command, callback function: CopyFiles */
#define  PANEL_TEXTMSG_2                  4       /* control type: textMsg, callback function: (none) */
#define  PANEL_TITEL2                     5       /* control type: textMsg, callback function: (none) */
#define  PANEL_SHOWLOG                    6       /* control type: command, callback function: ShowLog */
#define  PANEL_LANGUAGE                   7       /* control type: ring, callback function: LanguageSelected */
#define  PANEL_COPYCFGFILE                8       /* control type: radioButton, callback function: (none) */
#define  PANEL_CREATEBACKUP               9       /* control type: radioButton, callback function: (none) */
#define  PANEL_MODIFYFOLDERS              10      /* control type: radioButton, callback function: ModifyFolders */
#define  PANEL_CONFIGFILES                11      /* control type: string, callback function: FoldersModified */
#define  PANEL_CONFIGSELBUTTON            12      /* control type: command, callback function: SelectConfigFolder */
#define  PANEL_ICONFILES                  13      /* control type: string, callback function: FoldersModified */
#define  PANEL_ICONSELBUTTON              14      /* control type: command, callback function: SelectIconFolder */
#define  PANEL_TYPEPALETTES               15      /* control type: string, callback function: FoldersModified */
#define  PANEL_TYPEPALSELBUTTON           16      /* control type: command, callback function: SelectTypePaletteFolder */
#define  PANEL_SWITSINSTALLFOLDER         17      /* control type: string, callback function: SWITSInstallFolderModified */
#define  PANEL_INSTALLSELBUTTON           18      /* control type: command, callback function: SelectInstallFolder */

#define  PANEL_2                          4
#define  PANEL_2_TEXTBOX                  2       /* control type: textBox, callback function: (none) */
#define  PANEL_2_SAVE                     3       /* control type: command, callback function: SaveLogFile */
#define  PANEL_2_CLOSE                    4       /* control type: command, callback function: CloseLogFile */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_FILE                     2
#define  MENUBAR_FILE_CHANGEMEDRIVER      3       /* callback function: ChangeME */
#define  MENUBAR_FILE_SEPARATOR_2         4
#define  MENUBAR_FILE_ROBOCOPY_BACKUP     5       /* callback function: CreateRoboCopyBackUpScript */
#define  MENUBAR_FILE_SEPARATOR           6
#define  MENUBAR_FILE_EXIT                7       /* callback function: ExitProgram */
#define  MENUBAR_HELP                     8
#define  MENUBAR_HELP_ABOUT               9       /* callback function: AboutProgram */


     /* Callback Prototypes: */

void CVICALLBACK AboutProgram(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK ApplyDriver(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CancelDriver(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK ChangeME(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK ChangeMEDriver(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CloseBackupPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CloseLogFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CopyFiles(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CreateBackupPanelCallback(int panel, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK CreateRoboCopyBackUpScript(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK ExitProgram(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK FoldersModified(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FoldersModifiedBackup(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LanguageSelected(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MainPanelCallBack(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ModifyFolders(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveBatchFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SaveLogFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectBackupPath(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectBatchFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectConfigFolder(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectIconFolder(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectInstallFolder(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectLogFile(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectNICfg(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectNIDoc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectRSDoc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectRSProg(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectSWDoc(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectSWProg(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectTypePaletteFolder(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShowLog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SWITSInstallFolderModified(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK VersionSelected(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
