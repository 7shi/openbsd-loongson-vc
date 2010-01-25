/*
 * MACHINE GENERATED: DO NOT EDIT
 *
 * ioconf.c, from "GENERIC"
 */

#include <sys/param.h>
#include <sys/device.h>

extern struct cfdriver video_cd;
extern struct cfdriver rl_cd;
extern struct cfdriver pckbc_cd;
extern struct cfdriver uhci_cd;
extern struct cfdriver ohci_cd;
extern struct cfdriver ehci_cd;
extern struct cfdriver vscsi_cd;
extern struct cfdriver softraid_cd;
extern struct cfdriver sd_cd;
extern struct cfdriver cd_cd;
extern struct cfdriver wd_cd;
extern struct cfdriver atapiscsi_cd;
extern struct cfdriver isa_cd;
extern struct cfdriver rlphy_cd;
extern struct cfdriver ukphy_cd;
extern struct cfdriver urlphy_cd;
extern struct cfdriver pci_cd;
extern struct cfdriver pciide_cd;
extern struct cfdriver pckbd_cd;
extern struct cfdriver pmsi_cd;
extern struct cfdriver usb_cd;
extern struct cfdriver uhub_cd;
extern struct cfdriver uvideo_cd;
extern struct cfdriver uhidev_cd;
extern struct cfdriver uhid_cd;
extern struct cfdriver ukbd_cd;
extern struct cfdriver ums_cd;
extern struct cfdriver umass_cd;
extern struct cfdriver url_cd;
extern struct cfdriver urtw_cd;
extern struct cfdriver wsdisplay_cd;
extern struct cfdriver wskbd_cd;
extern struct cfdriver wsmouse_cd;
extern struct cfdriver scsibus_cd;
extern struct cfdriver ch_cd;
extern struct cfdriver st_cd;
extern struct cfdriver ss_cd;
extern struct cfdriver uk_cd;
extern struct cfdriver mainbus_cd;
extern struct cfdriver cpu_cd;
extern struct cfdriver clock_cd;
extern struct cfdriver bonito_cd;
extern struct cfdriver glxpcib_cd;
extern struct cfdriver mcclock_cd;
extern struct cfdriver smfb_cd;

extern struct cfattach video_ca;
extern struct cfattach vscsi_ca;
extern struct cfattach softraid_ca;
extern struct cfattach wd_ca;
extern struct cfattach atapiscsi_ca;
extern struct cfattach isa_ca;
extern struct cfattach pckbc_isa_ca;
extern struct cfattach rlphy_ca;
extern struct cfattach ukphy_ca;
extern struct cfattach urlphy_ca;
extern struct cfattach pci_ca;
extern struct cfattach pciide_pci_ca;
extern struct cfattach rl_pci_ca;
extern struct cfattach uhci_pci_ca;
extern struct cfattach ohci_pci_ca;
extern struct cfattach ehci_pci_ca;
extern struct cfattach pckbd_ca;
extern struct cfattach pmsi_ca;
extern struct cfattach usb_ca;
extern struct cfattach uhub_ca;
extern struct cfattach uhub_uhub_ca;
extern struct cfattach uvideo_ca;
extern struct cfattach uhidev_ca;
extern struct cfattach uhid_ca;
extern struct cfattach ukbd_ca;
extern struct cfattach ums_ca;
extern struct cfattach umass_ca;
extern struct cfattach url_ca;
extern struct cfattach urtw_ca;
extern struct cfattach wsdisplay_emul_ca;
extern struct cfattach wskbd_ca;
extern struct cfattach wsmouse_ca;
extern struct cfattach scsibus_ca;
extern struct cfattach cd_ca;
extern struct cfattach ch_ca;
extern struct cfattach sd_ca;
extern struct cfattach st_ca;
extern struct cfattach ss_ca;
extern struct cfattach uk_ca;
extern struct cfattach mainbus_ca;
extern struct cfattach cpu_ca;
extern struct cfattach clock_ca;
extern struct cfattach bonito_ca;
extern struct cfattach glxpcib_ca;
extern struct cfattach mcclock_isa_ca;
extern struct cfattach smfb_ca;


/* locators */
static int loc[23] = {
	0x70, 0, -1, 0, -1, -1, -1, -1,
	0, -1, 0, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, 1, 0,
};

#ifndef MAXEXTRALOC
#define MAXEXTRALOC 32
#endif
int extraloc[MAXEXTRALOC] = { -1 };
int nextraloc = MAXEXTRALOC;
int uextraloc = 0;

char *locnames[] = {
	"channel",
	"drive",
	"port",
	"size",
	"iomem",
	"iosiz",
	"irq",
	"drq",
	"drq2",
	"phy",
	"bus",
	"dev",
	"function",
	"slot",
	"configuration",
	"interface",
	"vendor",
	"product",
	"release",
	"reportid",
	"console",
	"mux",
	"target",
	"lun",
};

/* each entry is an index into locnames[]; -1 terminates */
short locnamp[] = {
	-1, 0, 1, -1, 0, -1, 2, 3,
	4, 5, 6, 7, 8, -1, 9, -1,
	9, -1, 10, -1, 11, 12, -1, 13,
	-1, 2, 14, 15, 16, 17, 18, -1,
	2, 14, 15, 16, 17, 18, -1, 19,
	-1, 20, 21, -1, 20, 21, -1, 20,
	21, -1, 21, -1, 21, -1, 22, 23,
	-1,
};

/* size of parent vectors */
int pv_size = 45;

/* parent vectors */
short pv[45] = {
	2, 1, 4, 26, -1, 14, 13, 15, -1, 27, 12, -1, 16, 24, -1, 19,
	20, -1, 17, 25, -1, 10, -1, 32, -1, 22, -1, 42, -1, 6, -1, 21,
	-1, 18, -1, 39, -1, 5, -1, 11, -1, 45, -1, 43, -1,
};

#define NORM FSTATE_NOTFOUND
#define STAR FSTATE_STAR
#define DNRM FSTATE_DNOTFOUND
#define DSTR FSTATE_DSTAR

struct cfdata cfdata[] = {
    /* attachment       driver        unit  state loc     flags parents nm ivstubs starunit1 */
/*  0: video* at uvideo* */
    {&video_ca,		&video_cd,	 0, STAR,     loc,    0, pv+31, 0, 0,    0},
/*  1: vscsi0 at root */
    {&vscsi_ca,		&vscsi_cd,	 0, NORM,     loc,    0, pv+ 4, 0, 0,    0},
/*  2: softraid0 at root */
    {&softraid_ca,	&softraid_cd,	 0, NORM,     loc,    0, pv+ 4, 0, 0,    0},
/*  3: wd* at pciide* channel -1 drive -1 */
    {&wd_ca,		&wd_cd,		 0, STAR, loc+ 18,    0, pv+39, 1, 0,    0},
/*  4: atapiscsi* at umass* channel -1 */
    {&atapiscsi_ca,	&atapiscsi_cd,	 0, STAR, loc+ 19,    0, pv+ 3, 4, 0,    0},
/*  5: isa0 at glxpcib* */
    {&isa_ca,		&isa_cd,	 0, NORM,     loc,    0, pv+43, 5, 0,    0},
/*  6: pckbc0 at isa0 port -1 size 0 iomem -1 iosiz 0 irq -1 drq -1 drq2 -1 */
    {&pckbc_isa_ca,	&pckbc_cd,	 0, NORM, loc+  7,    0, pv+37, 6, 0,    0},
/*  7: rlphy* at url*|rl* phy -1 */
    {&rlphy_ca,		&rlphy_cd,	 0, STAR, loc+ 19,    0, pv+ 9, 14, 0,    0},
/*  8: ukphy* at url*|rl* phy -1 */
    {&ukphy_ca,		&ukphy_cd,	 0, STAR, loc+ 19,    0, pv+ 9, 14, 0,    0},
/*  9: urlphy* at url*|rl* phy -1 */
    {&urlphy_ca,	&urlphy_cd,	 0, STAR, loc+ 19,    0, pv+ 9, 14, 0,    0},
/* 10: pci* at bonito* bus -1 */
    {&pci_ca,		&pci_cd,	 0, STAR, loc+ 19,    0, pv+27, 18, 0,    0},
/* 11: pciide* at pci* dev -1 function -1 */
    {&pciide_pci_ca,	&pciide_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 12: rl* at pci* dev -1 function -1 */
    {&rl_pci_ca,	&rl_cd,		 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 13: uhci* at pci* dev -1 function -1 */
    {&uhci_pci_ca,	&uhci_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 14: ohci* at pci* dev -1 function -1 */
    {&ohci_pci_ca,	&ohci_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 15: ehci* at pci* dev -1 function -1 */
    {&ehci_pci_ca,	&ehci_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 16: pckbd* at pckbc0 slot -1 */
    {&pckbd_ca,		&pckbd_cd,	 0, STAR, loc+ 19,    0, pv+29, 23, 0,    0},
/* 17: pmsi* at pckbc0 slot -1 */
    {&pmsi_ca,		&pmsi_cd,	 0, STAR, loc+ 19,    0, pv+29, 23, 0,    0},
/* 18: usb* at ohci*|uhci*|ehci* */
    {&usb_ca,		&usb_cd,	 0, STAR,     loc,    0, pv+ 5, 24, 0,    0},
/* 19: uhub* at usb* */
    {&uhub_ca,		&uhub_cd,	 0, STAR,     loc,    0, pv+33, 24, 0,    0},
/* 20: uhub* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&uhub_uhub_ca,	&uhub_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 21: uvideo* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&uvideo_ca,	&uvideo_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 22: uhidev* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&uhidev_ca,	&uhidev_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 23: uhid* at uhidev* reportid -1 */
    {&uhid_ca,		&uhid_cd,	 0, STAR, loc+ 19,    0, pv+25, 39, 0,    0},
/* 24: ukbd* at uhidev* reportid -1 */
    {&ukbd_ca,		&ukbd_cd,	 0, STAR, loc+ 19,    0, pv+25, 39, 0,    0},
/* 25: ums* at uhidev* reportid -1 */
    {&ums_ca,		&ums_cd,	 0, STAR, loc+ 19,    0, pv+25, 39, 0,    0},
/* 26: umass* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&umass_ca,		&umass_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 27: url* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&url_ca,		&url_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 28: urtw* at uhub*|uhub* port -1 configuration -1 interface -1 vendor -1 product -1 release -1 */
    {&urtw_ca,		&urtw_cd,	 0, STAR, loc+ 14,    0, pv+15, 25, 0,    0},
/* 29: wsdisplay* at smfb* console -1 mux 1 */
    {&wsdisplay_emul_ca,	&wsdisplay_cd,	 0, STAR, loc+ 20,    0, pv+41, 41, 0,    0},
/* 30: wskbd* at pckbd*|ukbd* console -1 mux 1 */
    {&wskbd_ca,		&wskbd_cd,	 0, STAR, loc+ 20,    0, pv+12, 44, 0,    0},
/* 31: wsmouse* at pmsi*|ums* mux 0 */
    {&wsmouse_ca,	&wsmouse_cd,	 0, STAR, loc+ 22,    0, pv+18, 50, 0,    0},
/* 32: scsibus* at softraid0|vscsi0|atapiscsi*|umass* */
    {&scsibus_ca,	&scsibus_cd,	 0, STAR,     loc,    0, pv+ 0, 53, 0,    0},
/* 33: cd* at scsibus* target -1 lun -1 */
    {&cd_ca,		&cd_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 34: ch* at scsibus* target -1 lun -1 */
    {&ch_ca,		&ch_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 35: sd* at scsibus* target -1 lun -1 */
    {&sd_ca,		&sd_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 36: st* at scsibus* target -1 lun -1 */
    {&st_ca,		&st_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 37: ss* at scsibus* target -1 lun -1 */
    {&ss_ca,		&ss_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 38: uk* at scsibus* target -1 lun -1 */
    {&uk_ca,		&uk_cd,		 0, STAR, loc+ 18,    0, pv+23, 54, 0,    0},
/* 39: mainbus0 at root */
    {&mainbus_ca,	&mainbus_cd,	 0, NORM,     loc,    0, pv+ 4, 0, 0,    0},
/* 40: cpu0 at mainbus0 */
    {&cpu_ca,		&cpu_cd,	 0, NORM,     loc,    0, pv+35, 56, 0,    0},
/* 41: clock0 at mainbus0 */
    {&clock_ca,		&clock_cd,	 0, NORM,     loc,    0, pv+35, 56, 0,    0},
/* 42: bonito* at mainbus0 */
    {&bonito_ca,	&bonito_cd,	 0, STAR,     loc,    0, pv+35, 56, 0,    0},
/* 43: glxpcib* at pci* dev -1 function -1 */
    {&glxpcib_ca,	&glxpcib_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
/* 44: mcclock0 at isa0 port 0x70 size 0 iomem -1 iosiz 0 irq -1 drq -1 drq2 -1 */
    {&mcclock_isa_ca,	&mcclock_cd,	 0, NORM, loc+  0,    0, pv+37, 6, 0,    0},
/* 45: smfb* at pci* dev -1 function -1 */
    {&smfb_ca,		&smfb_cd,	 0, STAR, loc+ 18,    0, pv+21, 20, 0,    0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {(struct cfattach *)-1}
};

short cfroots[] = {
	 1 /* vscsi0 */,
	 2 /* softraid0 */,
	39 /* mainbus0 */,
	-1
};

int cfroots_size = 4;

/* pseudo-devices */
extern void pfattach(int);
extern void pflogattach(int);
extern void pfsyncattach(int);
extern void pflowattach(int);
extern void spppattach(int);
extern void encattach(int);
extern void ptyattach(int);
extern void nmeaattach(int);
extern void mstsattach(int);
extern void endrunattach(int);
extern void vndattach(int);
extern void ccdattach(int);
extern void ksymsattach(int);
extern void systraceattach(int);
extern void bpfilterattach(int);
extern void bridgeattach(int);
extern void carpattach(int);
extern void gifattach(int);
extern void greattach(int);
extern void loopattach(int);
extern void pppattach(int);
extern void slattach(int);
extern void tunattach(int);
extern void vlanattach(int);
extern void trunkattach(int);
extern void vetherattach(int);
extern void pppoeattach(int);
extern void bioattach(int);

char *pdevnames[] = {
	"pf",
	"pflog",
	"pfsync",
	"pflow",
	"sppp",
	"enc",
	"pty",
	"nmea",
	"msts",
	"endrun",
	"vnd",
	"ccd",
	"ksyms",
	"systrace",
	"bpfilter",
	"bridge",
	"carp",
	"gif",
	"gre",
	"loop",
	"ppp",
	"sl",
	"tun",
	"vlan",
	"trunk",
	"vether",
	"pppoe",
	"bio",
};

int pdevnames_size = 28;

struct pdevinit pdevinit[] = {
	{ pfattach, 1 },
	{ pflogattach, 1 },
	{ pfsyncattach, 1 },
	{ pflowattach, 1 },
	{ spppattach, 1 },
	{ encattach, 1 },
	{ ptyattach, 16 },
	{ nmeaattach, 1 },
	{ mstsattach, 1 },
	{ endrunattach, 1 },
	{ vndattach, 4 },
	{ ccdattach, 4 },
	{ ksymsattach, 1 },
	{ systraceattach, 1 },
	{ bpfilterattach, 1 },
	{ bridgeattach, 1 },
	{ carpattach, 1 },
	{ gifattach, 1 },
	{ greattach, 1 },
	{ loopattach, 1 },
	{ pppattach, 1 },
	{ slattach, 1 },
	{ tunattach, 1 },
	{ vlanattach, 1 },
	{ trunkattach, 1 },
	{ vetherattach, 1 },
	{ pppoeattach, 1 },
	{ bioattach, 1 },
	{ NULL, 0 }
};
