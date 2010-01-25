IDENT=-DDDB -DDIAGNOSTIC -DKTRACE -DACCOUNTING -DKMEMSTATS -DPTRACE -DPOOL_DEBUG -DCRYPTO -DSYSVMSG -DSYSVSEM -DSYSVSHM -DUVM_SWAP_ENCRYPT -DCOMPAT_43 -DCOMPAT_O43 -DLKM -DFFS -DFFS2 -DFFS_SOFTUPDATES -DUFS_DIRHASH -DQUOTA -DEXT2FS -DMFS -DNNPFS -DTCP_SACK -DTCP_ECN -DTCP_SIGNATURE -DNFSCLIENT -DNFSSERVER -DCD9660 -DUDF -DMSDOSFS -DFIFO -DINET -DALTQ -DINET6 -DIPSEC -DPPP_BSDCOMP -DPPP_DEFLATE -DMROUTING -DBOOT_CONFIG -DCPU_LOONGSON2 -DUSER_PCICONF -DPCIVERBOSE -DUSBVERBOSE
PARAM=-DMAXUSERS=32
S=	src
LINK_ADDRESS=0xffffffff80200000
#	$OpenBSD: Makefile.loongson,v 1.1.1.1 2009/12/25 21:05:14 miod Exp $

# Makefile for OpenBSD
#
# This makefile is constructed from a machine description:
#	config ``machineid''
# Most changes should be made in the machine description
#	/sys/arch/loongson/conf/``machineid''
# after which you should do
#	 config ``machineid''
# Machine generic makefile changes should be made in
#	/sys/arch/loongson/conf/Makefile.``machinetype''
# after which config should be rerun for all machines of that type.
#
# N.B.: NO DEPENDENCIES ON FOLLOWING FLAGS ARE VISIBLE TO MAKEFILE
#	IF YOU CHANGE THE DEFINITION OF ANY OF THESE RECOMPILE EVERYTHING
#
# -DTRACE	compile in kernel tracing hooks
# -DQUOTA	compile in file system quotas


# DEBUG is set to -g if debugging
# PROF is set to -pg if profiling

.include <bsd.own.mk>

AS?=	as
CC?=	cc
MKDEP?=	mkdep
SIZE?=	size
CPP?=	cpp
LD?=	ld ${ENDIAN}
STRIP?=	strip
TOUCH?=	touch

CPP+=${ENDIAN}
CC+=${ENDIAN}
AS+=${ENDIAN}
LD+=${ENDIAN}

# source tree is located via $S relative to the compilation directory
.ifndef S
S!=	cd ../../../..; pwd
.endif
LOONGSON=$S/arch/loongson
MIPS64=	$S/arch/mips64

INCLUDES=	-I. -Iinclude -I$S -I$S/arch -nostdinc
CPPFLAGS=	${INCLUDES} ${IDENT} -D_KERNEL -D__loongson__
CDIAGFLAGS=	-Werror -Wall -Wmissing-prototypes -Wstrict-prototypes \
		-Wno-uninitialized -Wno-format -Wno-main \
		-Wstack-larger-than-2047 -Wvariable-decl
CMACHFLAGS+=	-mno-abicalls ${ABI} -msoft-float \
		-fno-builtin-printf -fno-builtin-log
.if ${IDENT:M-DNO_PROPOLICE}
CMACHFLAGS+=	-fno-stack-protector
.endif
COPTS?=		-O2
CFLAGS=		${DEBUG} ${CDIAGFLAGS} ${CMACHFLAGS} ${COPTS} ${PIPE}
AFLAGS=		-x assembler-with-cpp -mno-abicalls ${ABI} -D_LOCORE
STRIPFLAGS=	-g -X -x

NORMAL_C_NOP=	${CC} ${CFLAGS} ${CPPFLAGS} -c $<
NORMAL_C=	${CC} ${CFLAGS} ${CPPFLAGS} ${PROF} -c $<
NORMAL_C_C=	${CC} ${CFLAGS} ${CPPFLAGS} ${PROF} ${PARAM} -c $<
NORMAL_S=	${CC} ${AFLAGS} ${CPPFLAGS} -c $<
NORMAL_S_C=	${AS}  ${COPTS} ${PARAM} $< -o $@

LINTS=	wdc.ln rtl81x9.ln pckbc.ln uhci.ln ohci.ln ehci.ln vscsi.ln \
	softraid.ln softraid_raid0.ln softraid_raid1.ln softraid_raidp.ln \
	softraid_crypto.ln softraid_raid6.ln ksyms.ln pf.ln pf_norm.ln \
	pf_ruleset.ln pf_ioctl.ln pf_table.ln pf_osfp.ln pf_if.ln \
	pf_lb.ln if_pflog.ln if_pfsync.ln if_pflow.ln bio.ln if_pppoe.ln \
	altq_subr.ln altq_red.ln altq_cbq.ln altq_rmclass.ln altq_hfsc.ln \
	altq_priq.ln db_access.ln db_aout.ln db_break.ln db_command.ln \
	db_elf.ln db_examine.ln db_expr.ln db_hangman.ln db_input.ln \
	db_lex.ln db_output.ln db_print.ln db_run.ln db_sym.ln db_trap.ln \
	db_variables.ln db_watch.ln db_write_cmd.ln db_usrreq.ln ccd.ln \
	cons.ln firmload.ln systrace.ln vnd.ln rnd.ln video.ln \
	cd9660_bmap.ln cd9660_lookup.ln cd9660_node.ln cd9660_rrip.ln \
	cd9660_util.ln cd9660_vfsops.ln cd9660_vnops.ln udf_subr.ln \
	udf_vfsops.ln udf_vnops.ln clock_subr.ln exec_aout.ln \
	exec_conf.ln exec_ecoff.ln exec_elf32.ln exec_elf64.ln \
	exec_script.ln exec_subr.ln init_main.ln init_sysent.ln \
	kern_acct.ln kern_clock.ln kern_descrip.ln kern_event.ln \
	kern_exec.ln kern_exit.ln kern_fork.ln kern_kthread.ln \
	kern_ktrace.ln kern_lock.ln kern_lkm.ln kern_malloc.ln \
	kern_rwlock.ln kern_physio.ln kern_proc.ln kern_prot.ln \
	kern_resource.ln kern_sched.ln kern_sensors.ln kern_sig.ln \
	kern_subr.ln kern_sysctl.ln kern_synch.ln kern_tc.ln kern_time.ln \
	kern_timeout.ln kern_watchdog.ln kern_workq.ln kern_xxx.ln \
	sched_bsd.ln subr_autoconf.ln subr_disk.ln subr_evcount.ln \
	subr_extent.ln subr_log.ln subr_pool.ln subr_prf.ln subr_prof.ln \
	subr_userconf.ln subr_xxx.ln sys_generic.ln sys_pipe.ln \
	sys_process.ln sys_socket.ln sysv_ipc.ln sysv_msg.ln sysv_sem.ln \
	sysv_shm.ln tty.ln tty_conf.ln tty_pty.ln tty_nmea.ln tty_msts.ln \
	tty_endrun.ln tty_subr.ln tty_tty.ln uipc_domain.ln uipc_mbuf.ln \
	uipc_mbuf2.ln uipc_proto.ln uipc_socket.ln uipc_socket2.ln \
	uipc_syscalls.ln uipc_usrreq.ln vfs_bio.ln vfs_biomem.ln \
	vfs_cache.ln vfs_cluster.ln vfs_conf.ln vfs_default.ln \
	vfs_init.ln vfs_lockf.ln vfs_lookup.ln vfs_subr.ln vfs_sync.ln \
	vfs_syscalls.ln vfs_vnops.ln vfs_getcwd.ln vnode_if.ln \
	dead_vnops.ln fifo_vnops.ln spec_vnops.ln spec_subr.ln \
	msdosfs_conv.ln msdosfs_denode.ln msdosfs_fat.ln \
	msdosfs_lookup.ln msdosfs_vfsops.ln msdosfs_vnops.ln bpf.ln \
	bpf_filter.ln if.ln if_ethersubr.ln if_spppsubr.ln if_loop.ln \
	if_media.ln if_sl.ln if_ppp.ln ppp_tty.ln bsd-comp.ln \
	ppp-deflate.ln zlib.ln if_tun.ln if_bridge.ln bridgestp.ln \
	if_vlan.ln radix.ln radix_mpath.ln raw_cb.ln raw_usrreq.ln \
	route.ln rtsock.ln slcompress.ln if_enc.ln if_gre.ln if_trunk.ln \
	trunklacp.ln if_vether.ln ieee80211.ln ieee80211_amrr.ln \
	ieee80211_crypto.ln ieee80211_crypto_bip.ln \
	ieee80211_crypto_ccmp.ln ieee80211_crypto_tkip.ln \
	ieee80211_crypto_wep.ln ieee80211_input.ln ieee80211_ioctl.ln \
	ieee80211_node.ln ieee80211_output.ln ieee80211_pae_input.ln \
	ieee80211_pae_output.ln ieee80211_proto.ln ieee80211_rssadapt.ln \
	ieee80211_regdomain.ln if_ether.ln igmp.ln in.ln in_pcb.ln \
	in_proto.ln ip_divert.ln ip_icmp.ln ip_id.ln ip_input.ln \
	ip_mroute.ln ip_output.ln raw_ip.ln tcp_debug.ln tcp_input.ln \
	tcp_output.ln tcp_subr.ln tcp_timer.ln tcp_usrreq.ln \
	udp_usrreq.ln ip_gre.ln ip_ipsp.ln ip_spd.ln ip_ipip.ln \
	ip_ether.ln ipsec_input.ln ipsec_output.ln ip_esp.ln ip_ah.ln \
	ip_carp.ln ip_ipcomp.ln rijndael.ln md5.ln rmd160.ln sha1.ln \
	sha2.ln blf.ln cast.ln skipjack.ln ecb_enc.ln set_key.ln \
	ecb3_enc.ln crypto.ln cryptodev.ln criov.ln cryptosoft.ln \
	xform.ln deflate.ln arc4.ln michael.ln cmac.ln hmac.ln \
	key_wrap.ln idgen.ln krpc_subr.ln nfs_bio.ln nfs_boot.ln \
	nfs_debug.ln nfs_node.ln nfs_kq.ln nfs_serv.ln nfs_socket.ln \
	nfs_srvcache.ln nfs_subs.ln nfs_syscalls.ln nfs_vfsops.ln \
	nfs_vnops.ln ffs_alloc.ln ffs_balloc.ln ffs_inode.ln ffs_subr.ln \
	ffs_softdep_stub.ln ffs_tables.ln ffs_vfsops.ln ffs_vnops.ln \
	ffs_softdep.ln mfs_vfsops.ln mfs_vnops.ln ufs_bmap.ln \
	ufs_dirhash.ln ufs_ihash.ln ufs_inode.ln ufs_lookup.ln \
	ufs_quota.ln ufs_quota_stub.ln ufs_vfsops.ln ufs_vnops.ln \
	ext2fs_alloc.ln ext2fs_balloc.ln ext2fs_bmap.ln ext2fs_bswap.ln \
	ext2fs_inode.ln ext2fs_lookup.ln ext2fs_readwrite.ln \
	ext2fs_subr.ln ext2fs_vfsops.ln ext2fs_vnops.ln \
	nnpfs_common-bsd.ln nnpfs_deb.ln nnpfs_dev-bsd.ln \
	nnpfs_dev-common.ln nnpfs_message.ln nnpfs_node.ln \
	nnpfs_node-bsd.ln nnpfs_syscalls-common.ln nnpfs_vfsops-bsd.ln \
	nnpfs_vfsops-common.ln nnpfs_vfsops-openbsd.ln \
	nnpfs_vnodeops-bsd.ln nnpfs_vnodeops-common.ln uvm_amap.ln \
	uvm_anon.ln uvm_aobj.ln uvm_device.ln uvm_fault.ln uvm_glue.ln \
	uvm_init.ln uvm_io.ln uvm_km.ln uvm_map.ln uvm_meter.ln \
	uvm_mmap.ln uvm_object.ln uvm_page.ln uvm_pager.ln uvm_pdaemon.ln \
	uvm_pglist.ln uvm_stat.ln uvm_swap.ln uvm_swap_encrypt.ln \
	uvm_unix.ln uvm_user.ln uvm_vnode.ln if_gif.ln ip_ecn.ln \
	in_gif.ln in6_gif.ln in6_pcb.ln in6.ln ip6_divert.ln \
	in6_ifattach.ln in6_cksum.ln in6_src.ln in6_proto.ln dest6.ln \
	frag6.ln icmp6.ln ip6_id.ln ip6_input.ln ip6_forward.ln \
	ip6_mroute.ln ip6_output.ln route6.ln mld6.ln nd6.ln nd6_nbr.ln \
	nd6_rtr.ln raw_ip6.ln udp6_output.ln pfkey.ln pfkeyv2.ln \
	pfkeyv2_parsemessage.ln pfkeyv2_convert.ln compat_exec.ln \
	compat_util.ln compat_dir.ln vfs_syscalls_o43.ln kern_exit_43.ln \
	kern_info_43.ln kern_resource_43.ln kern_sig_43.ln tty_43.ln \
	uipc_syscalls_43.ln vfs_syscalls_43.ln vm_43.ln getsn.ln \
	random.ln strchr.ln strrchr.ln __main.ln imax.ln imin.ln lmax.ln \
	lmin.ln max.ln min.ln ulmax.ln ulmin.ln memchr.ln memcmp.ln \
	memset.ln strlcat.ln strlcpy.ln strncmp.ln strncpy.ln scanc.ln \
	skpc.ln strncasecmp.ln clock.ln cpu.ln interrupt.ln mem.ln \
	pmap.ln process_machdep.ln sendsig.ln softintr.ln sys_machdep.ln \
	trap.ln vm_machdep.ln db_disasm.ln db_machdep.ln in_cksum.ln \
	in4_cksum.ln cninit.ln autoconf.ln bus_dma.ln bus_space.ln \
	conf.ln disksubr.ln loongson2_machdep.ln machdep.ln mutex.ln \
	pciide_machdep.ln pmon.ln wscons_machdep.ln wd.ln ata_wdc.ln \
	ata.ln atapiscsi.ln isa.ln pckbc_isa.ln mii.ln mii_physubr.ln \
	ukphy_subr.ln rlphy.ln ukphy.ln urlphy.ln pci.ln pci_map.ln \
	pci_quirks.ln pci_subr.ln cy82c693.ln pciide.ln if_rl_pci.ln \
	uhci_pci.ln ohci_pci.ln ehci_pci.ln pckbd.ln wskbdmap_mfii.ln \
	pms_intelli.ln usb.ln usbdi.ln usbdi_util.ln usb_mem.ln \
	usb_subr.ln usb_quirks.ln uhub.ln uvideo.ln hid.ln uhidev.ln \
	uhid.ln ukbd.ln ukbdmap.ln ums.ln umass.ln umass_quirks.ln \
	umass_scsi.ln if_url.ln if_urtw.ln rasops.ln rasops15.ln \
	wsdisplay.ln wsevent.ln wskbd.ln wskbdutil.ln wsmouse.ln \
	wsemulconf.ln wsemul_vt100.ln wsemul_vt100_subr.ln \
	wsemul_vt100_chars.ln wsemul_vt100_keys.ln wsfont.ln scsi_base.ln \
	scsi_ioctl.ln scsiconf.ln cd.ln ch.ln sd.ln st.ln ss.ln \
	ss_mustek.ln ss_scanjet.ln uk.ln mainbus.ln bonito.ln glx.ln \
	glxpcib.ln pcib.ln mcclock.ln mcclock_isa.ln smfb.ln

OBJS=	${LINTS:.ln=.o} bcmp.o bzero.o bcopy.o ovbcopy.o memcpy.o \
	memmove.o ffs.o strcmp.o strlen.o htonl.o htons.o \
	cache_loongson2.o context.o cp0access.o exception.o fp.o \
	lcore_access.o lcore_float.o tlbhandler.o lcore_ddb.o \
	pmon32.o

CFILES=	$S/dev/ic/wdc.c $S/dev/ic/rtl81x9.c $S/dev/ic/pckbc.c \
	$S/dev/usb/uhci.c $S/dev/usb/ohci.c $S/dev/usb/ehci.c \
	$S/dev/vscsi.c $S/dev/softraid.c $S/dev/softraid_raid0.c \
	$S/dev/softraid_raid1.c $S/dev/softraid_raidp.c \
	$S/dev/softraid_crypto.c $S/dev/softraid_raid6.c $S/dev/ksyms.c \
	$S/net/pf.c $S/net/pf_norm.c $S/net/pf_ruleset.c \
	$S/net/pf_ioctl.c $S/net/pf_table.c $S/net/pf_osfp.c \
	$S/net/pf_if.c $S/net/pf_lb.c $S/net/if_pflog.c \
	$S/net/if_pfsync.c $S/net/if_pflow.c $S/dev/bio.c \
	$S/net/if_pppoe.c $S/altq/altq_subr.c $S/altq/altq_red.c \
	$S/altq/altq_cbq.c $S/altq/altq_rmclass.c $S/altq/altq_hfsc.c \
	$S/altq/altq_priq.c $S/ddb/db_access.c $S/ddb/db_aout.c \
	$S/ddb/db_break.c $S/ddb/db_command.c $S/ddb/db_elf.c \
	$S/ddb/db_examine.c $S/ddb/db_expr.c $S/ddb/db_hangman.c \
	$S/ddb/db_input.c $S/ddb/db_lex.c $S/ddb/db_output.c \
	$S/ddb/db_print.c $S/ddb/db_run.c $S/ddb/db_sym.c \
	$S/ddb/db_trap.c $S/ddb/db_variables.c $S/ddb/db_watch.c \
	$S/ddb/db_write_cmd.c $S/ddb/db_usrreq.c $S/dev/ccd.c \
	$S/dev/cons.c $S/dev/firmload.c $S/dev/systrace.c $S/dev/vnd.c \
	$S/dev/rnd.c $S/dev/video.c $S/isofs/cd9660/cd9660_bmap.c \
	$S/isofs/cd9660/cd9660_lookup.c $S/isofs/cd9660/cd9660_node.c \
	$S/isofs/cd9660/cd9660_rrip.c $S/isofs/cd9660/cd9660_util.c \
	$S/isofs/cd9660/cd9660_vfsops.c $S/isofs/cd9660/cd9660_vnops.c \
	$S/isofs/udf/udf_subr.c $S/isofs/udf/udf_vfsops.c \
	$S/isofs/udf/udf_vnops.c $S/kern/clock_subr.c $S/kern/exec_aout.c \
	$S/kern/exec_conf.c $S/kern/exec_ecoff.c $S/kern/exec_elf32.c \
	$S/kern/exec_elf64.c $S/kern/exec_script.c $S/kern/exec_subr.c \
	$S/kern/init_main.c $S/kern/init_sysent.c $S/kern/kern_acct.c \
	$S/kern/kern_clock.c $S/kern/kern_descrip.c $S/kern/kern_event.c \
	$S/kern/kern_exec.c $S/kern/kern_exit.c $S/kern/kern_fork.c \
	$S/kern/kern_kthread.c $S/kern/kern_ktrace.c $S/kern/kern_lock.c \
	$S/kern/kern_lkm.c $S/kern/kern_malloc.c $S/kern/kern_rwlock.c \
	$S/kern/kern_physio.c $S/kern/kern_proc.c $S/kern/kern_prot.c \
	$S/kern/kern_resource.c $S/kern/kern_sched.c \
	$S/kern/kern_sensors.c $S/kern/kern_sig.c $S/kern/kern_subr.c \
	$S/kern/kern_sysctl.c $S/kern/kern_synch.c $S/kern/kern_tc.c \
	$S/kern/kern_time.c $S/kern/kern_timeout.c \
	$S/kern/kern_watchdog.c $S/kern/kern_workq.c $S/kern/kern_xxx.c \
	$S/kern/sched_bsd.c $S/kern/subr_autoconf.c $S/kern/subr_disk.c \
	$S/kern/subr_evcount.c $S/kern/subr_extent.c $S/kern/subr_log.c \
	$S/kern/subr_pool.c $S/kern/subr_prf.c $S/kern/subr_prof.c \
	$S/kern/subr_userconf.c $S/kern/subr_xxx.c $S/kern/sys_generic.c \
	$S/kern/sys_pipe.c $S/kern/sys_process.c $S/kern/sys_socket.c \
	$S/kern/sysv_ipc.c $S/kern/sysv_msg.c $S/kern/sysv_sem.c \
	$S/kern/sysv_shm.c $S/kern/tty.c $S/kern/tty_conf.c \
	$S/kern/tty_pty.c $S/kern/tty_nmea.c $S/kern/tty_msts.c \
	$S/kern/tty_endrun.c $S/kern/tty_subr.c $S/kern/tty_tty.c \
	$S/kern/uipc_domain.c $S/kern/uipc_mbuf.c $S/kern/uipc_mbuf2.c \
	$S/kern/uipc_proto.c $S/kern/uipc_socket.c $S/kern/uipc_socket2.c \
	$S/kern/uipc_syscalls.c $S/kern/uipc_usrreq.c $S/kern/vfs_bio.c \
	$S/kern/vfs_biomem.c $S/kern/vfs_cache.c $S/kern/vfs_cluster.c \
	$S/kern/vfs_conf.c $S/kern/vfs_default.c $S/kern/vfs_init.c \
	$S/kern/vfs_lockf.c $S/kern/vfs_lookup.c $S/kern/vfs_subr.c \
	$S/kern/vfs_sync.c $S/kern/vfs_syscalls.c $S/kern/vfs_vnops.c \
	$S/kern/vfs_getcwd.c $S/kern/vnode_if.c \
	$S/miscfs/deadfs/dead_vnops.c $S/miscfs/fifofs/fifo_vnops.c \
	$S/miscfs/specfs/spec_vnops.c $S/miscfs/specfs/spec_subr.c \
	$S/msdosfs/msdosfs_conv.c $S/msdosfs/msdosfs_denode.c \
	$S/msdosfs/msdosfs_fat.c $S/msdosfs/msdosfs_lookup.c \
	$S/msdosfs/msdosfs_vfsops.c $S/msdosfs/msdosfs_vnops.c \
	$S/net/bpf.c $S/net/bpf_filter.c $S/net/if.c \
	$S/net/if_ethersubr.c $S/net/if_spppsubr.c $S/net/if_loop.c \
	$S/net/if_media.c $S/net/if_sl.c $S/net/if_ppp.c $S/net/ppp_tty.c \
	$S/net/bsd-comp.c $S/net/ppp-deflate.c $S/net/zlib.c \
	$S/net/if_tun.c $S/net/if_bridge.c $S/net/bridgestp.c \
	$S/net/if_vlan.c $S/net/radix.c $S/net/radix_mpath.c \
	$S/net/raw_cb.c $S/net/raw_usrreq.c $S/net/route.c \
	$S/net/rtsock.c $S/net/slcompress.c $S/net/if_enc.c \
	$S/net/if_gre.c $S/net/if_trunk.c $S/net/trunklacp.c \
	$S/net/if_vether.c $S/net80211/ieee80211.c \
	$S/net80211/ieee80211_amrr.c $S/net80211/ieee80211_crypto.c \
	$S/net80211/ieee80211_crypto_bip.c \
	$S/net80211/ieee80211_crypto_ccmp.c \
	$S/net80211/ieee80211_crypto_tkip.c \
	$S/net80211/ieee80211_crypto_wep.c $S/net80211/ieee80211_input.c \
	$S/net80211/ieee80211_ioctl.c $S/net80211/ieee80211_node.c \
	$S/net80211/ieee80211_output.c $S/net80211/ieee80211_pae_input.c \
	$S/net80211/ieee80211_pae_output.c $S/net80211/ieee80211_proto.c \
	$S/net80211/ieee80211_rssadapt.c \
	$S/net80211/ieee80211_regdomain.c $S/netinet/if_ether.c \
	$S/netinet/igmp.c $S/netinet/in.c $S/netinet/in_pcb.c \
	$S/netinet/in_proto.c $S/netinet/ip_divert.c $S/netinet/ip_icmp.c \
	$S/netinet/ip_id.c $S/netinet/ip_input.c $S/netinet/ip_mroute.c \
	$S/netinet/ip_output.c $S/netinet/raw_ip.c $S/netinet/tcp_debug.c \
	$S/netinet/tcp_input.c $S/netinet/tcp_output.c \
	$S/netinet/tcp_subr.c $S/netinet/tcp_timer.c \
	$S/netinet/tcp_usrreq.c $S/netinet/udp_usrreq.c \
	$S/netinet/ip_gre.c $S/netinet/ip_ipsp.c $S/netinet/ip_spd.c \
	$S/netinet/ip_ipip.c $S/netinet/ip_ether.c \
	$S/netinet/ipsec_input.c $S/netinet/ipsec_output.c \
	$S/netinet/ip_esp.c $S/netinet/ip_ah.c $S/netinet/ip_carp.c \
	$S/netinet/ip_ipcomp.c $S/crypto/rijndael.c $S/crypto/md5.c \
	$S/crypto/rmd160.c $S/crypto/sha1.c $S/crypto/sha2.c \
	$S/crypto/blf.c $S/crypto/cast.c $S/crypto/skipjack.c \
	$S/crypto/ecb_enc.c $S/crypto/set_key.c $S/crypto/ecb3_enc.c \
	$S/crypto/crypto.c $S/crypto/cryptodev.c $S/crypto/criov.c \
	$S/crypto/cryptosoft.c $S/crypto/xform.c $S/crypto/deflate.c \
	$S/crypto/arc4.c $S/crypto/michael.c $S/crypto/cmac.c \
	$S/crypto/hmac.c $S/crypto/key_wrap.c $S/crypto/idgen.c \
	$S/nfs/krpc_subr.c $S/nfs/nfs_bio.c $S/nfs/nfs_boot.c \
	$S/nfs/nfs_debug.c $S/nfs/nfs_node.c $S/nfs/nfs_kq.c \
	$S/nfs/nfs_serv.c $S/nfs/nfs_socket.c $S/nfs/nfs_srvcache.c \
	$S/nfs/nfs_subs.c $S/nfs/nfs_syscalls.c $S/nfs/nfs_vfsops.c \
	$S/nfs/nfs_vnops.c $S/ufs/ffs/ffs_alloc.c $S/ufs/ffs/ffs_balloc.c \
	$S/ufs/ffs/ffs_inode.c $S/ufs/ffs/ffs_subr.c \
	$S/ufs/ffs/ffs_softdep_stub.c $S/ufs/ffs/ffs_tables.c \
	$S/ufs/ffs/ffs_vfsops.c $S/ufs/ffs/ffs_vnops.c \
	$S/ufs/ffs/ffs_softdep.c $S/ufs/mfs/mfs_vfsops.c \
	$S/ufs/mfs/mfs_vnops.c $S/ufs/ufs/ufs_bmap.c \
	$S/ufs/ufs/ufs_dirhash.c $S/ufs/ufs/ufs_ihash.c \
	$S/ufs/ufs/ufs_inode.c $S/ufs/ufs/ufs_lookup.c \
	$S/ufs/ufs/ufs_quota.c $S/ufs/ufs/ufs_quota_stub.c \
	$S/ufs/ufs/ufs_vfsops.c $S/ufs/ufs/ufs_vnops.c \
	$S/ufs/ext2fs/ext2fs_alloc.c $S/ufs/ext2fs/ext2fs_balloc.c \
	$S/ufs/ext2fs/ext2fs_bmap.c $S/ufs/ext2fs/ext2fs_bswap.c \
	$S/ufs/ext2fs/ext2fs_inode.c $S/ufs/ext2fs/ext2fs_lookup.c \
	$S/ufs/ext2fs/ext2fs_readwrite.c $S/ufs/ext2fs/ext2fs_subr.c \
	$S/ufs/ext2fs/ext2fs_vfsops.c $S/ufs/ext2fs/ext2fs_vnops.c \
	$S/nnpfs/nnpfs_common-bsd.c $S/nnpfs/nnpfs_deb.c \
	$S/nnpfs/nnpfs_dev-bsd.c $S/nnpfs/nnpfs_dev-common.c \
	$S/nnpfs/nnpfs_message.c $S/nnpfs/nnpfs_node.c \
	$S/nnpfs/nnpfs_node-bsd.c $S/nnpfs/nnpfs_syscalls-common.c \
	$S/nnpfs/nnpfs_vfsops-bsd.c $S/nnpfs/nnpfs_vfsops-common.c \
	$S/nnpfs/nnpfs_vfsops-openbsd.c $S/nnpfs/nnpfs_vnodeops-bsd.c \
	$S/nnpfs/nnpfs_vnodeops-common.c $S/uvm/uvm_amap.c \
	$S/uvm/uvm_anon.c $S/uvm/uvm_aobj.c $S/uvm/uvm_device.c \
	$S/uvm/uvm_fault.c $S/uvm/uvm_glue.c $S/uvm/uvm_init.c \
	$S/uvm/uvm_io.c $S/uvm/uvm_km.c $S/uvm/uvm_map.c \
	$S/uvm/uvm_meter.c $S/uvm/uvm_mmap.c $S/uvm/uvm_object.c \
	$S/uvm/uvm_page.c $S/uvm/uvm_pager.c $S/uvm/uvm_pdaemon.c \
	$S/uvm/uvm_pglist.c $S/uvm/uvm_stat.c $S/uvm/uvm_swap.c \
	$S/uvm/uvm_swap_encrypt.c $S/uvm/uvm_unix.c $S/uvm/uvm_user.c \
	$S/uvm/uvm_vnode.c $S/net/if_gif.c $S/netinet/ip_ecn.c \
	$S/netinet/in_gif.c $S/netinet6/in6_gif.c $S/netinet6/in6_pcb.c \
	$S/netinet6/in6.c $S/netinet6/ip6_divert.c \
	$S/netinet6/in6_ifattach.c $S/netinet6/in6_cksum.c \
	$S/netinet6/in6_src.c $S/netinet6/in6_proto.c $S/netinet6/dest6.c \
	$S/netinet6/frag6.c $S/netinet6/icmp6.c $S/netinet6/ip6_id.c \
	$S/netinet6/ip6_input.c $S/netinet6/ip6_forward.c \
	$S/netinet6/ip6_mroute.c $S/netinet6/ip6_output.c \
	$S/netinet6/route6.c $S/netinet6/mld6.c $S/netinet6/nd6.c \
	$S/netinet6/nd6_nbr.c $S/netinet6/nd6_rtr.c $S/netinet6/raw_ip6.c \
	$S/netinet6/udp6_output.c $S/net/pfkey.c $S/net/pfkeyv2.c \
	$S/net/pfkeyv2_parsemessage.c $S/net/pfkeyv2_convert.c \
	$S/compat/common/compat_exec.c $S/compat/common/compat_util.c \
	$S/compat/common/compat_dir.c $S/compat/common/vfs_syscalls_o43.c \
	$S/compat/common/kern_exit_43.c $S/compat/common/kern_info_43.c \
	$S/compat/common/kern_resource_43.c \
	$S/compat/common/kern_sig_43.c $S/compat/common/tty_43.c \
	$S/compat/common/uipc_syscalls_43.c \
	$S/compat/common/vfs_syscalls_43.c $S/compat/common/vm_43.c \
	$S/lib/libkern/getsn.c $S/lib/libkern/random.c \
	$S/lib/libkern/strchr.c $S/lib/libkern/strrchr.c \
	$S/lib/libkern/__main.c $S/lib/libkern/imax.c \
	$S/lib/libkern/imin.c $S/lib/libkern/lmax.c $S/lib/libkern/lmin.c \
	$S/lib/libkern/max.c $S/lib/libkern/min.c $S/lib/libkern/ulmax.c \
	$S/lib/libkern/ulmin.c $S/lib/libkern/memchr.c \
	$S/lib/libkern/memcmp.c $S/lib/libkern/memset.c \
	$S/lib/libkern/strlcat.c $S/lib/libkern/strlcpy.c \
	$S/lib/libkern/strncmp.c $S/lib/libkern/strncpy.c \
	$S/lib/libkern/scanc.c $S/lib/libkern/skpc.c \
	$S/lib/libkern/strncasecmp.c $S/arch/mips64/mips64/clock.c \
	$S/arch/mips64/mips64/cpu.c $S/arch/mips64/mips64/interrupt.c \
	$S/arch/mips64/mips64/mem.c $S/arch/mips64/mips64/pmap.c \
	$S/arch/mips64/mips64/process_machdep.c \
	$S/arch/mips64/mips64/sendsig.c $S/arch/mips64/mips64/softintr.c \
	$S/arch/mips64/mips64/sys_machdep.c $S/arch/mips64/mips64/trap.c \
	$S/arch/mips64/mips64/vm_machdep.c \
	$S/arch/mips64/mips64/db_disasm.c \
	$S/arch/mips64/mips64/db_machdep.c $S/netinet/in_cksum.c \
	$S/netinet/in4_cksum.c $S/dev/cninit.c \
	$S/arch/loongson/loongson/autoconf.c \
	$S/arch/loongson/loongson/bus_dma.c \
	$S/arch/loongson/loongson/bus_space.c \
	$S/arch/loongson/loongson/conf.c \
	$S/arch/loongson/loongson/disksubr.c \
	$S/arch/loongson/loongson/loongson2_machdep.c \
	$S/arch/loongson/loongson/machdep.c \
	$S/arch/loongson/loongson/mutex.c \
	$S/arch/loongson/loongson/pciide_machdep.c \
	$S/arch/loongson/loongson/pmon.c \
	$S/arch/loongson/loongson/wscons_machdep.c $S/dev/ata/wd.c \
	$S/dev/ata/ata_wdc.c $S/dev/ata/ata.c \
	$S/dev/atapiscsi/atapiscsi.c $S/dev/isa/isa.c \
	$S/dev/isa/pckbc_isa.c $S/dev/mii/mii.c $S/dev/mii/mii_physubr.c \
	$S/dev/mii/ukphy_subr.c $S/dev/mii/rlphy.c $S/dev/mii/ukphy.c \
	$S/dev/mii/urlphy.c $S/dev/pci/pci.c $S/dev/pci/pci_map.c \
	$S/dev/pci/pci_quirks.c $S/dev/pci/pci_subr.c \
	$S/dev/pci/cy82c693.c $S/dev/pci/pciide.c $S/dev/pci/if_rl_pci.c \
	$S/dev/pci/uhci_pci.c $S/dev/pci/ohci_pci.c $S/dev/pci/ehci_pci.c \
	$S/dev/pckbc/pckbd.c $S/dev/pckbc/wskbdmap_mfii.c \
	$S/dev/pckbc/pms_intelli.c $S/dev/usb/usb.c $S/dev/usb/usbdi.c \
	$S/dev/usb/usbdi_util.c $S/dev/usb/usb_mem.c \
	$S/dev/usb/usb_subr.c $S/dev/usb/usb_quirks.c $S/dev/usb/uhub.c \
	$S/dev/usb/uvideo.c $S/dev/usb/hid.c $S/dev/usb/uhidev.c \
	$S/dev/usb/uhid.c $S/dev/usb/ukbd.c $S/dev/usb/ukbdmap.c \
	$S/dev/usb/ums.c $S/dev/usb/umass.c $S/dev/usb/umass_quirks.c \
	$S/dev/usb/umass_scsi.c $S/dev/usb/if_url.c $S/dev/usb/if_urtw.c \
	$S/dev/rasops/rasops.c $S/dev/rasops/rasops15.c \
	$S/dev/wscons/wsdisplay.c $S/dev/wscons/wsevent.c \
	$S/dev/wscons/wskbd.c $S/dev/wscons/wskbdutil.c \
	$S/dev/wscons/wsmouse.c $S/dev/wscons/wsemulconf.c \
	$S/dev/wscons/wsemul_vt100.c $S/dev/wscons/wsemul_vt100_subr.c \
	$S/dev/wscons/wsemul_vt100_chars.c \
	$S/dev/wscons/wsemul_vt100_keys.c $S/dev/wsfont/wsfont.c \
	$S/scsi/scsi_base.c $S/scsi/scsi_ioctl.c $S/scsi/scsiconf.c \
	$S/scsi/cd.c $S/scsi/ch.c $S/scsi/sd.c $S/scsi/st.c $S/scsi/ss.c \
	$S/scsi/ss_mustek.c $S/scsi/ss_scanjet.c $S/scsi/uk.c \
	$S/arch/loongson/dev/mainbus.c $S/arch/loongson/dev/bonito.c \
	$S/arch/loongson/dev/glx.c $S/arch/loongson/dev/glxpcib.c \
	$S/arch/loongson/dev/pcib.c $S/arch/loongson/dev/mcclock.c \
	$S/arch/loongson/dev/mcclock_isa.c $S/arch/loongson/dev/smfb.c \
	$S/conf/swapgeneric.c

SFILES=	$S/lib/libkern/arch/mips64/bcmp.S \
	$S/lib/libkern/arch/mips64/bzero.S \
	$S/lib/libkern/arch/mips64/bcopy.S \
	$S/lib/libkern/arch/mips64/ovbcopy.S \
	$S/lib/libkern/arch/mips64/memcpy.S \
	$S/lib/libkern/arch/mips64/memmove.S \
	$S/lib/libkern/arch/mips64/ffs.S \
	$S/lib/libkern/arch/mips64/strcmp.S \
	$S/lib/libkern/arch/mips64/strlen.S \
	$S/lib/libkern/arch/mips64/htonl.S \
	$S/lib/libkern/arch/mips64/htons.S \
	$S/arch/mips64/mips64/cache_loongson2.S \
	$S/arch/mips64/mips64/context.S $S/arch/mips64/mips64/cp0access.S \
	$S/arch/mips64/mips64/exception.S $S/arch/mips64/mips64/fp.S \
	$S/arch/mips64/mips64/lcore_access.S \
	$S/arch/mips64/mips64/lcore_float.S \
	$S/arch/mips64/mips64/tlbhandler.S \
	$S/arch/mips64/mips64/lcore_ddb.S \
	$S/arch/loongson/loongson/pmon32.S

# load lines for config "xxx" will be emitted as:
# xxx: ${SYSTEM_DEP} swapxxx.o
#	${SYSTEM_LD_HEAD}
#	${SYSTEM_LD} swapxxx.o
#	${SYSTEM_LD_TAIL}
SYSTEM_OBJ=	locore.o param.o ioconf.o ${OBJS}
SYSTEM_DEP=	Makefile ${SYSTEM_OBJ}
SYSTEM_LD_HEAD=	rm -f $@
SYSTEM_LD=	@if [ X${DEBUG} = X-g ]; \
		then strip=-X; \
		else strip=-x; \
		fi; \
		echo ${LD} $$strip -o $@ -e start -T ${LOONGSON}/conf/ld.script \
			-Ttext=${LINK_ADDRESS} '$${SYSTEM_OBJ}' vers.o; \
		${LD} $$strip -o $@ -e start -T ${LOONGSON}/conf/ld.script \
			-Ttext=${LINK_ADDRESS} ${SYSTEM_OBJ} vers.o
SYSTEM_LD_TAIL=	chmod 755 $@; \
		${SIZE} $@

DEBUG?=
.if ${DEBUG} == "-g"
SYSTEM_LD_TAIL+=; \
		echo mv $@ $@.gdb; rm -f $@.gdb; mv $@ $@.gdb; \
		echo ${STRIP} ${STRIPFLAGS} -o $@ $@.gdb; \
		${STRIP} ${STRIPFLAGS} -o $@ $@.gdb
.endif

all: bsd

bsd: ${SYSTEM_DEP} swapgeneric.o vers.o
	${SYSTEM_LD_HEAD}
	${SYSTEM_LD} swapgeneric.o
	${SYSTEM_LD_TAIL}

swapgeneric.o: $S/conf/swapgeneric.c
	${NORMAL_C}


clean::
	rm -f eddep bsd bsd.gdb bsd.ecoff tags *.o locore.i [a-z]*.s \
	    Errs errs linterrs makelinks

lint: /tmp param.c
	@lint -hbxn -DGENERIC -Dvolatile= ${COPTS} ${PARAM} -UKGDB \
	    ${CFILES} ioconf.c param.c

symbols.sort: ${LOONGSON}/loongson/symbols.raw
	grep -v '^#' ${LOONGSON}/loongson/symbols.raw \
	    | sed 's/^	//' | sort -u > symbols.sort

locore.o: ${LOONGSON}/loongson/locore.S assym.h
	${NORMAL_S}

# the following are necessary because the files depend on the types of
# cpu's included in the system configuration
clock.o machdep.o autoconf.o conf.o locore.o: Makefile

# depend on network configuration
uipc_domain.o uipc_proto.o vfs_conf.o: Makefile
if_tun.o if_loop.o if_ethersubr.o: Makefile
if_arp.o if_ether.o: Makefile
ip_input.o ip_output.o in_pcb.o in_proto.o: Makefile
tcp_subr.o tcp_timer.o tcp_output.o: Makefile

assym.h: $S/kern/genassym.sh ${LOONGSON}/loongson/genassym.cf Makefile
	sh $S/kern/genassym.sh ${CC} ${CFLAGS} ${CPPFLAGS} \
	    ${PARAM} < ${LOONGSON}/loongson/genassym.cf > assym.h.tmp && \
	    mv -f assym.h.tmp assym.h

links:
	egrep '#if' ${CFILES} | sed -f $S/conf/defines | \
	  sed -e 's/:.*//' -e 's/\.c/.o/' | sort -u > dontlink
	echo ${CFILES} | tr -s ' ' '\12' | sed 's/\.c/.o/' | \
	  sort -u | comm -23 - dontlink | \
	  sed 's,../.*/\(.*.o\),rm -f \1;ln -s ../GENERIC/\1 \1,' > makelinks
	sh makelinks && rm -f dontlink

tags:
	@echo "see $S/kern/Makefile for tags"

param.c: $S/conf/param.c
	rm -f param.c
	cp $S/conf/param.c .

param.o: param.c Makefile
	${NORMAL_C_C}

mcount.o: $S/lib/libkern/mcount.c Makefile
	${NORMAL_C_NOP}

ioconf.o: ioconf.c
	${NORMAL_C}

vers.o: ${SYSTEM_DEP} ${SYSTEM_SWAP_DEP}
	sh $S/conf/newvers.sh
	${CC} ${CFLAGS} ${CPPFLAGS} ${PROF} -c vers.c

SRCS=   ${LOONGSON}/loongson/locore.S \
	param.c ioconf.c ${CFILES} ${SFILES}
depend:: .depend
.depend: ${SRCS} assym.h param.c
	${MKDEP} ${AFLAGS} ${CPPFLAGS} ${LOONGSON}/loongson/locore.S
	${MKDEP} -a ${CFLAGS} ${CPPFLAGS} param.c ioconf.c ${CFILES}
	${MKDEP} -a ${AFLAGS} ${CPPFLAGS} ${SFILES}
	sh $S/kern/genassym.sh ${MKDEP} -f assym.dep ${CFLAGS} \
	    ${CPPFLAGS} < ${LOONGSON}/loongson/genassym.cf
	@sed -e 's/.*\.o: /assym.h: /' -e 's/\/tmp\/genassym_c.[^ ]*//' \
	    < assym.dep >> .depend
	@rm -f assym.dep

# The install target can be redefined by putting a
# install-kernel-${MACHINE_NAME} target into /etc/mk.conf
MACHINE_NAME!=  uname -n
install: install-kernel-${MACHINE_NAME}
.if !target(install-kernel-${MACHINE_NAME}})
install-kernel-${MACHINE_NAME}:
	rm -f /obsd
	ln /bsd /obsd
	cp bsd /nbsd
	mv /nbsd /bsd
.endif

.SUFFIXES:
.SUFFIXES: .s .S .c .o .ln

.c.o:
	${NORMAL_C}

.c.ln:
	${LINT_C}

.s.o:
	${NORMAL_S}

.s.ln:
	${LINT_S}

.S.o:
	${NORMAL_S}

.S.ln:
	${LINT_S}

wdc.o wdc.ln: $S/dev/ic/wdc.c
rtl81x9.o rtl81x9.ln: $S/dev/ic/rtl81x9.c
pckbc.o pckbc.ln: $S/dev/ic/pckbc.c
uhci.o uhci.ln: $S/dev/usb/uhci.c
ohci.o ohci.ln: $S/dev/usb/ohci.c
ehci.o ehci.ln: $S/dev/usb/ehci.c
vscsi.o vscsi.ln: $S/dev/vscsi.c
softraid.o softraid.ln: $S/dev/softraid.c
softraid_raid0.o softraid_raid0.ln: $S/dev/softraid_raid0.c
softraid_raid1.o softraid_raid1.ln: $S/dev/softraid_raid1.c
softraid_raidp.o softraid_raidp.ln: $S/dev/softraid_raidp.c
softraid_crypto.o softraid_crypto.ln: $S/dev/softraid_crypto.c
softraid_raid6.o softraid_raid6.ln: $S/dev/softraid_raid6.c
ksyms.o ksyms.ln: $S/dev/ksyms.c
pf.o pf.ln: $S/net/pf.c
pf_norm.o pf_norm.ln: $S/net/pf_norm.c
pf_ruleset.o pf_ruleset.ln: $S/net/pf_ruleset.c
pf_ioctl.o pf_ioctl.ln: $S/net/pf_ioctl.c
pf_table.o pf_table.ln: $S/net/pf_table.c
pf_osfp.o pf_osfp.ln: $S/net/pf_osfp.c
pf_if.o pf_if.ln: $S/net/pf_if.c
pf_lb.o pf_lb.ln: $S/net/pf_lb.c
if_pflog.o if_pflog.ln: $S/net/if_pflog.c
if_pfsync.o if_pfsync.ln: $S/net/if_pfsync.c
if_pflow.o if_pflow.ln: $S/net/if_pflow.c
bio.o bio.ln: $S/dev/bio.c
if_pppoe.o if_pppoe.ln: $S/net/if_pppoe.c
altq_subr.o altq_subr.ln: $S/altq/altq_subr.c
altq_red.o altq_red.ln: $S/altq/altq_red.c
altq_cbq.o altq_cbq.ln: $S/altq/altq_cbq.c
altq_rmclass.o altq_rmclass.ln: $S/altq/altq_rmclass.c
altq_hfsc.o altq_hfsc.ln: $S/altq/altq_hfsc.c
altq_priq.o altq_priq.ln: $S/altq/altq_priq.c
db_access.o db_access.ln: $S/ddb/db_access.c
db_aout.o db_aout.ln: $S/ddb/db_aout.c
db_break.o db_break.ln: $S/ddb/db_break.c
db_command.o db_command.ln: $S/ddb/db_command.c
db_elf.o db_elf.ln: $S/ddb/db_elf.c
db_examine.o db_examine.ln: $S/ddb/db_examine.c
db_expr.o db_expr.ln: $S/ddb/db_expr.c
db_hangman.o db_hangman.ln: $S/ddb/db_hangman.c
db_input.o db_input.ln: $S/ddb/db_input.c
db_lex.o db_lex.ln: $S/ddb/db_lex.c
db_output.o db_output.ln: $S/ddb/db_output.c
db_print.o db_print.ln: $S/ddb/db_print.c
db_run.o db_run.ln: $S/ddb/db_run.c
db_sym.o db_sym.ln: $S/ddb/db_sym.c
db_trap.o db_trap.ln: $S/ddb/db_trap.c
db_variables.o db_variables.ln: $S/ddb/db_variables.c
db_watch.o db_watch.ln: $S/ddb/db_watch.c
db_write_cmd.o db_write_cmd.ln: $S/ddb/db_write_cmd.c
db_usrreq.o db_usrreq.ln: $S/ddb/db_usrreq.c
ccd.o ccd.ln: $S/dev/ccd.c
cons.o cons.ln: $S/dev/cons.c
firmload.o firmload.ln: $S/dev/firmload.c
systrace.o systrace.ln: $S/dev/systrace.c
vnd.o vnd.ln: $S/dev/vnd.c
rnd.o rnd.ln: $S/dev/rnd.c
video.o video.ln: $S/dev/video.c
cd9660_bmap.o cd9660_bmap.ln: $S/isofs/cd9660/cd9660_bmap.c
cd9660_lookup.o cd9660_lookup.ln: $S/isofs/cd9660/cd9660_lookup.c
cd9660_node.o cd9660_node.ln: $S/isofs/cd9660/cd9660_node.c
cd9660_rrip.o cd9660_rrip.ln: $S/isofs/cd9660/cd9660_rrip.c
cd9660_util.o cd9660_util.ln: $S/isofs/cd9660/cd9660_util.c
cd9660_vfsops.o cd9660_vfsops.ln: $S/isofs/cd9660/cd9660_vfsops.c
cd9660_vnops.o cd9660_vnops.ln: $S/isofs/cd9660/cd9660_vnops.c
udf_subr.o udf_subr.ln: $S/isofs/udf/udf_subr.c
udf_vfsops.o udf_vfsops.ln: $S/isofs/udf/udf_vfsops.c
udf_vnops.o udf_vnops.ln: $S/isofs/udf/udf_vnops.c
clock_subr.o clock_subr.ln: $S/kern/clock_subr.c
exec_aout.o exec_aout.ln: $S/kern/exec_aout.c
exec_conf.o exec_conf.ln: $S/kern/exec_conf.c
exec_ecoff.o exec_ecoff.ln: $S/kern/exec_ecoff.c
exec_elf32.o exec_elf32.ln: $S/kern/exec_elf32.c
exec_elf64.o exec_elf64.ln: $S/kern/exec_elf64.c
exec_script.o exec_script.ln: $S/kern/exec_script.c
exec_subr.o exec_subr.ln: $S/kern/exec_subr.c
init_main.o init_main.ln: $S/kern/init_main.c
init_sysent.o init_sysent.ln: $S/kern/init_sysent.c
kern_acct.o kern_acct.ln: $S/kern/kern_acct.c
kern_clock.o kern_clock.ln: $S/kern/kern_clock.c
kern_descrip.o kern_descrip.ln: $S/kern/kern_descrip.c
kern_event.o kern_event.ln: $S/kern/kern_event.c
kern_exec.o kern_exec.ln: $S/kern/kern_exec.c
kern_exit.o kern_exit.ln: $S/kern/kern_exit.c
kern_fork.o kern_fork.ln: $S/kern/kern_fork.c
kern_kthread.o kern_kthread.ln: $S/kern/kern_kthread.c
kern_ktrace.o kern_ktrace.ln: $S/kern/kern_ktrace.c
kern_lock.o kern_lock.ln: $S/kern/kern_lock.c
kern_lkm.o kern_lkm.ln: $S/kern/kern_lkm.c
kern_malloc.o kern_malloc.ln: $S/kern/kern_malloc.c
kern_rwlock.o kern_rwlock.ln: $S/kern/kern_rwlock.c
kern_physio.o kern_physio.ln: $S/kern/kern_physio.c
kern_proc.o kern_proc.ln: $S/kern/kern_proc.c
kern_prot.o kern_prot.ln: $S/kern/kern_prot.c
kern_resource.o kern_resource.ln: $S/kern/kern_resource.c
kern_sched.o kern_sched.ln: $S/kern/kern_sched.c
kern_sensors.o kern_sensors.ln: $S/kern/kern_sensors.c
kern_sig.o kern_sig.ln: $S/kern/kern_sig.c
kern_subr.o kern_subr.ln: $S/kern/kern_subr.c
kern_sysctl.o kern_sysctl.ln: $S/kern/kern_sysctl.c
kern_synch.o kern_synch.ln: $S/kern/kern_synch.c
kern_tc.o kern_tc.ln: $S/kern/kern_tc.c
kern_time.o kern_time.ln: $S/kern/kern_time.c
kern_timeout.o kern_timeout.ln: $S/kern/kern_timeout.c
kern_watchdog.o kern_watchdog.ln: $S/kern/kern_watchdog.c
kern_workq.o kern_workq.ln: $S/kern/kern_workq.c
kern_xxx.o kern_xxx.ln: $S/kern/kern_xxx.c
sched_bsd.o sched_bsd.ln: $S/kern/sched_bsd.c
subr_autoconf.o subr_autoconf.ln: $S/kern/subr_autoconf.c
subr_disk.o subr_disk.ln: $S/kern/subr_disk.c
subr_evcount.o subr_evcount.ln: $S/kern/subr_evcount.c
subr_extent.o subr_extent.ln: $S/kern/subr_extent.c
subr_log.o subr_log.ln: $S/kern/subr_log.c
subr_pool.o subr_pool.ln: $S/kern/subr_pool.c
subr_prf.o subr_prf.ln: $S/kern/subr_prf.c
subr_prof.o subr_prof.ln: $S/kern/subr_prof.c
subr_userconf.o subr_userconf.ln: $S/kern/subr_userconf.c
subr_xxx.o subr_xxx.ln: $S/kern/subr_xxx.c
sys_generic.o sys_generic.ln: $S/kern/sys_generic.c
sys_pipe.o sys_pipe.ln: $S/kern/sys_pipe.c
sys_process.o sys_process.ln: $S/kern/sys_process.c
sys_socket.o sys_socket.ln: $S/kern/sys_socket.c
sysv_ipc.o sysv_ipc.ln: $S/kern/sysv_ipc.c
sysv_msg.o sysv_msg.ln: $S/kern/sysv_msg.c
sysv_sem.o sysv_sem.ln: $S/kern/sysv_sem.c
sysv_shm.o sysv_shm.ln: $S/kern/sysv_shm.c
tty.o tty.ln: $S/kern/tty.c
tty_conf.o tty_conf.ln: $S/kern/tty_conf.c
tty_pty.o tty_pty.ln: $S/kern/tty_pty.c
tty_nmea.o tty_nmea.ln: $S/kern/tty_nmea.c
tty_msts.o tty_msts.ln: $S/kern/tty_msts.c
tty_endrun.o tty_endrun.ln: $S/kern/tty_endrun.c
tty_subr.o tty_subr.ln: $S/kern/tty_subr.c
tty_tty.o tty_tty.ln: $S/kern/tty_tty.c
uipc_domain.o uipc_domain.ln: $S/kern/uipc_domain.c
uipc_mbuf.o uipc_mbuf.ln: $S/kern/uipc_mbuf.c
uipc_mbuf2.o uipc_mbuf2.ln: $S/kern/uipc_mbuf2.c
uipc_proto.o uipc_proto.ln: $S/kern/uipc_proto.c
uipc_socket.o uipc_socket.ln: $S/kern/uipc_socket.c
uipc_socket2.o uipc_socket2.ln: $S/kern/uipc_socket2.c
uipc_syscalls.o uipc_syscalls.ln: $S/kern/uipc_syscalls.c
uipc_usrreq.o uipc_usrreq.ln: $S/kern/uipc_usrreq.c
vfs_bio.o vfs_bio.ln: $S/kern/vfs_bio.c
vfs_biomem.o vfs_biomem.ln: $S/kern/vfs_biomem.c
vfs_cache.o vfs_cache.ln: $S/kern/vfs_cache.c
vfs_cluster.o vfs_cluster.ln: $S/kern/vfs_cluster.c
vfs_conf.o vfs_conf.ln: $S/kern/vfs_conf.c
vfs_default.o vfs_default.ln: $S/kern/vfs_default.c
vfs_init.o vfs_init.ln: $S/kern/vfs_init.c
vfs_lockf.o vfs_lockf.ln: $S/kern/vfs_lockf.c
vfs_lookup.o vfs_lookup.ln: $S/kern/vfs_lookup.c
vfs_subr.o vfs_subr.ln: $S/kern/vfs_subr.c
vfs_sync.o vfs_sync.ln: $S/kern/vfs_sync.c
vfs_syscalls.o vfs_syscalls.ln: $S/kern/vfs_syscalls.c
vfs_vnops.o vfs_vnops.ln: $S/kern/vfs_vnops.c
vfs_getcwd.o vfs_getcwd.ln: $S/kern/vfs_getcwd.c
vnode_if.o vnode_if.ln: $S/kern/vnode_if.c
dead_vnops.o dead_vnops.ln: $S/miscfs/deadfs/dead_vnops.c
fifo_vnops.o fifo_vnops.ln: $S/miscfs/fifofs/fifo_vnops.c
spec_vnops.o spec_vnops.ln: $S/miscfs/specfs/spec_vnops.c
spec_subr.o spec_subr.ln: $S/miscfs/specfs/spec_subr.c
msdosfs_conv.o msdosfs_conv.ln: $S/msdosfs/msdosfs_conv.c
msdosfs_denode.o msdosfs_denode.ln: $S/msdosfs/msdosfs_denode.c
msdosfs_fat.o msdosfs_fat.ln: $S/msdosfs/msdosfs_fat.c
msdosfs_lookup.o msdosfs_lookup.ln: $S/msdosfs/msdosfs_lookup.c
msdosfs_vfsops.o msdosfs_vfsops.ln: $S/msdosfs/msdosfs_vfsops.c
msdosfs_vnops.o msdosfs_vnops.ln: $S/msdosfs/msdosfs_vnops.c
bpf.o bpf.ln: $S/net/bpf.c
bpf_filter.o bpf_filter.ln: $S/net/bpf_filter.c
if.o if.ln: $S/net/if.c
if_ethersubr.o if_ethersubr.ln: $S/net/if_ethersubr.c
if_spppsubr.o if_spppsubr.ln: $S/net/if_spppsubr.c
if_loop.o if_loop.ln: $S/net/if_loop.c
if_media.o if_media.ln: $S/net/if_media.c
if_sl.o if_sl.ln: $S/net/if_sl.c
if_ppp.o if_ppp.ln: $S/net/if_ppp.c
ppp_tty.o ppp_tty.ln: $S/net/ppp_tty.c
bsd-comp.o bsd-comp.ln: $S/net/bsd-comp.c
ppp-deflate.o ppp-deflate.ln: $S/net/ppp-deflate.c
zlib.o zlib.ln: $S/net/zlib.c
if_tun.o if_tun.ln: $S/net/if_tun.c
if_bridge.o if_bridge.ln: $S/net/if_bridge.c
bridgestp.o bridgestp.ln: $S/net/bridgestp.c
if_vlan.o if_vlan.ln: $S/net/if_vlan.c
radix.o radix.ln: $S/net/radix.c
radix_mpath.o radix_mpath.ln: $S/net/radix_mpath.c
raw_cb.o raw_cb.ln: $S/net/raw_cb.c
raw_usrreq.o raw_usrreq.ln: $S/net/raw_usrreq.c
route.o route.ln: $S/net/route.c
rtsock.o rtsock.ln: $S/net/rtsock.c
slcompress.o slcompress.ln: $S/net/slcompress.c
if_enc.o if_enc.ln: $S/net/if_enc.c
if_gre.o if_gre.ln: $S/net/if_gre.c
if_trunk.o if_trunk.ln: $S/net/if_trunk.c
trunklacp.o trunklacp.ln: $S/net/trunklacp.c
if_vether.o if_vether.ln: $S/net/if_vether.c
ieee80211.o ieee80211.ln: $S/net80211/ieee80211.c
ieee80211_amrr.o ieee80211_amrr.ln: $S/net80211/ieee80211_amrr.c
ieee80211_crypto.o ieee80211_crypto.ln: $S/net80211/ieee80211_crypto.c
ieee80211_crypto_bip.o ieee80211_crypto_bip.ln: $S/net80211/ieee80211_crypto_bip.c
ieee80211_crypto_ccmp.o ieee80211_crypto_ccmp.ln: $S/net80211/ieee80211_crypto_ccmp.c
ieee80211_crypto_tkip.o ieee80211_crypto_tkip.ln: $S/net80211/ieee80211_crypto_tkip.c
ieee80211_crypto_wep.o ieee80211_crypto_wep.ln: $S/net80211/ieee80211_crypto_wep.c
ieee80211_input.o ieee80211_input.ln: $S/net80211/ieee80211_input.c
ieee80211_ioctl.o ieee80211_ioctl.ln: $S/net80211/ieee80211_ioctl.c
ieee80211_node.o ieee80211_node.ln: $S/net80211/ieee80211_node.c
ieee80211_output.o ieee80211_output.ln: $S/net80211/ieee80211_output.c
ieee80211_pae_input.o ieee80211_pae_input.ln: $S/net80211/ieee80211_pae_input.c
ieee80211_pae_output.o ieee80211_pae_output.ln: $S/net80211/ieee80211_pae_output.c
ieee80211_proto.o ieee80211_proto.ln: $S/net80211/ieee80211_proto.c
ieee80211_rssadapt.o ieee80211_rssadapt.ln: $S/net80211/ieee80211_rssadapt.c
ieee80211_regdomain.o ieee80211_regdomain.ln: $S/net80211/ieee80211_regdomain.c
if_ether.o if_ether.ln: $S/netinet/if_ether.c
igmp.o igmp.ln: $S/netinet/igmp.c
in.o in.ln: $S/netinet/in.c
in_pcb.o in_pcb.ln: $S/netinet/in_pcb.c
in_proto.o in_proto.ln: $S/netinet/in_proto.c
ip_divert.o ip_divert.ln: $S/netinet/ip_divert.c
ip_icmp.o ip_icmp.ln: $S/netinet/ip_icmp.c
ip_id.o ip_id.ln: $S/netinet/ip_id.c
ip_input.o ip_input.ln: $S/netinet/ip_input.c
ip_mroute.o ip_mroute.ln: $S/netinet/ip_mroute.c
ip_output.o ip_output.ln: $S/netinet/ip_output.c
raw_ip.o raw_ip.ln: $S/netinet/raw_ip.c
tcp_debug.o tcp_debug.ln: $S/netinet/tcp_debug.c
tcp_input.o tcp_input.ln: $S/netinet/tcp_input.c
tcp_output.o tcp_output.ln: $S/netinet/tcp_output.c
tcp_subr.o tcp_subr.ln: $S/netinet/tcp_subr.c
tcp_timer.o tcp_timer.ln: $S/netinet/tcp_timer.c
tcp_usrreq.o tcp_usrreq.ln: $S/netinet/tcp_usrreq.c
udp_usrreq.o udp_usrreq.ln: $S/netinet/udp_usrreq.c
ip_gre.o ip_gre.ln: $S/netinet/ip_gre.c
ip_ipsp.o ip_ipsp.ln: $S/netinet/ip_ipsp.c
ip_spd.o ip_spd.ln: $S/netinet/ip_spd.c
ip_ipip.o ip_ipip.ln: $S/netinet/ip_ipip.c
ip_ether.o ip_ether.ln: $S/netinet/ip_ether.c
ipsec_input.o ipsec_input.ln: $S/netinet/ipsec_input.c
ipsec_output.o ipsec_output.ln: $S/netinet/ipsec_output.c
ip_esp.o ip_esp.ln: $S/netinet/ip_esp.c
ip_ah.o ip_ah.ln: $S/netinet/ip_ah.c
ip_carp.o ip_carp.ln: $S/netinet/ip_carp.c
ip_ipcomp.o ip_ipcomp.ln: $S/netinet/ip_ipcomp.c
rijndael.o rijndael.ln: $S/crypto/rijndael.c
md5.o md5.ln: $S/crypto/md5.c
rmd160.o rmd160.ln: $S/crypto/rmd160.c
sha1.o sha1.ln: $S/crypto/sha1.c
sha2.o sha2.ln: $S/crypto/sha2.c
blf.o blf.ln: $S/crypto/blf.c
cast.o cast.ln: $S/crypto/cast.c
skipjack.o skipjack.ln: $S/crypto/skipjack.c
ecb_enc.o ecb_enc.ln: $S/crypto/ecb_enc.c
set_key.o set_key.ln: $S/crypto/set_key.c
ecb3_enc.o ecb3_enc.ln: $S/crypto/ecb3_enc.c
crypto.o crypto.ln: $S/crypto/crypto.c
cryptodev.o cryptodev.ln: $S/crypto/cryptodev.c
criov.o criov.ln: $S/crypto/criov.c
cryptosoft.o cryptosoft.ln: $S/crypto/cryptosoft.c
xform.o xform.ln: $S/crypto/xform.c
deflate.o deflate.ln: $S/crypto/deflate.c
arc4.o arc4.ln: $S/crypto/arc4.c
michael.o michael.ln: $S/crypto/michael.c
cmac.o cmac.ln: $S/crypto/cmac.c
hmac.o hmac.ln: $S/crypto/hmac.c
key_wrap.o key_wrap.ln: $S/crypto/key_wrap.c
idgen.o idgen.ln: $S/crypto/idgen.c
krpc_subr.o krpc_subr.ln: $S/nfs/krpc_subr.c
nfs_bio.o nfs_bio.ln: $S/nfs/nfs_bio.c
nfs_boot.o nfs_boot.ln: $S/nfs/nfs_boot.c
nfs_debug.o nfs_debug.ln: $S/nfs/nfs_debug.c
nfs_node.o nfs_node.ln: $S/nfs/nfs_node.c
nfs_kq.o nfs_kq.ln: $S/nfs/nfs_kq.c
nfs_serv.o nfs_serv.ln: $S/nfs/nfs_serv.c
nfs_socket.o nfs_socket.ln: $S/nfs/nfs_socket.c
nfs_srvcache.o nfs_srvcache.ln: $S/nfs/nfs_srvcache.c
nfs_subs.o nfs_subs.ln: $S/nfs/nfs_subs.c
nfs_syscalls.o nfs_syscalls.ln: $S/nfs/nfs_syscalls.c
nfs_vfsops.o nfs_vfsops.ln: $S/nfs/nfs_vfsops.c
nfs_vnops.o nfs_vnops.ln: $S/nfs/nfs_vnops.c
ffs_alloc.o ffs_alloc.ln: $S/ufs/ffs/ffs_alloc.c
ffs_balloc.o ffs_balloc.ln: $S/ufs/ffs/ffs_balloc.c
ffs_inode.o ffs_inode.ln: $S/ufs/ffs/ffs_inode.c
ffs_subr.o ffs_subr.ln: $S/ufs/ffs/ffs_subr.c
ffs_softdep_stub.o ffs_softdep_stub.ln: $S/ufs/ffs/ffs_softdep_stub.c
ffs_tables.o ffs_tables.ln: $S/ufs/ffs/ffs_tables.c
ffs_vfsops.o ffs_vfsops.ln: $S/ufs/ffs/ffs_vfsops.c
ffs_vnops.o ffs_vnops.ln: $S/ufs/ffs/ffs_vnops.c
ffs_softdep.o ffs_softdep.ln: $S/ufs/ffs/ffs_softdep.c
mfs_vfsops.o mfs_vfsops.ln: $S/ufs/mfs/mfs_vfsops.c
mfs_vnops.o mfs_vnops.ln: $S/ufs/mfs/mfs_vnops.c
ufs_bmap.o ufs_bmap.ln: $S/ufs/ufs/ufs_bmap.c
ufs_dirhash.o ufs_dirhash.ln: $S/ufs/ufs/ufs_dirhash.c
ufs_ihash.o ufs_ihash.ln: $S/ufs/ufs/ufs_ihash.c
ufs_inode.o ufs_inode.ln: $S/ufs/ufs/ufs_inode.c
ufs_lookup.o ufs_lookup.ln: $S/ufs/ufs/ufs_lookup.c
ufs_quota.o ufs_quota.ln: $S/ufs/ufs/ufs_quota.c
ufs_quota_stub.o ufs_quota_stub.ln: $S/ufs/ufs/ufs_quota_stub.c
ufs_vfsops.o ufs_vfsops.ln: $S/ufs/ufs/ufs_vfsops.c
ufs_vnops.o ufs_vnops.ln: $S/ufs/ufs/ufs_vnops.c
ext2fs_alloc.o ext2fs_alloc.ln: $S/ufs/ext2fs/ext2fs_alloc.c
ext2fs_balloc.o ext2fs_balloc.ln: $S/ufs/ext2fs/ext2fs_balloc.c
ext2fs_bmap.o ext2fs_bmap.ln: $S/ufs/ext2fs/ext2fs_bmap.c
ext2fs_bswap.o ext2fs_bswap.ln: $S/ufs/ext2fs/ext2fs_bswap.c
ext2fs_inode.o ext2fs_inode.ln: $S/ufs/ext2fs/ext2fs_inode.c
ext2fs_lookup.o ext2fs_lookup.ln: $S/ufs/ext2fs/ext2fs_lookup.c
ext2fs_readwrite.o ext2fs_readwrite.ln: $S/ufs/ext2fs/ext2fs_readwrite.c
ext2fs_subr.o ext2fs_subr.ln: $S/ufs/ext2fs/ext2fs_subr.c
ext2fs_vfsops.o ext2fs_vfsops.ln: $S/ufs/ext2fs/ext2fs_vfsops.c
ext2fs_vnops.o ext2fs_vnops.ln: $S/ufs/ext2fs/ext2fs_vnops.c
nnpfs_common-bsd.o nnpfs_common-bsd.ln: $S/nnpfs/nnpfs_common-bsd.c
nnpfs_deb.o nnpfs_deb.ln: $S/nnpfs/nnpfs_deb.c
nnpfs_dev-bsd.o nnpfs_dev-bsd.ln: $S/nnpfs/nnpfs_dev-bsd.c
nnpfs_dev-common.o nnpfs_dev-common.ln: $S/nnpfs/nnpfs_dev-common.c
nnpfs_message.o nnpfs_message.ln: $S/nnpfs/nnpfs_message.c
nnpfs_node.o nnpfs_node.ln: $S/nnpfs/nnpfs_node.c
nnpfs_node-bsd.o nnpfs_node-bsd.ln: $S/nnpfs/nnpfs_node-bsd.c
nnpfs_syscalls-common.o nnpfs_syscalls-common.ln: $S/nnpfs/nnpfs_syscalls-common.c
nnpfs_vfsops-bsd.o nnpfs_vfsops-bsd.ln: $S/nnpfs/nnpfs_vfsops-bsd.c
nnpfs_vfsops-common.o nnpfs_vfsops-common.ln: $S/nnpfs/nnpfs_vfsops-common.c
nnpfs_vfsops-openbsd.o nnpfs_vfsops-openbsd.ln: $S/nnpfs/nnpfs_vfsops-openbsd.c
nnpfs_vnodeops-bsd.o nnpfs_vnodeops-bsd.ln: $S/nnpfs/nnpfs_vnodeops-bsd.c
nnpfs_vnodeops-common.o nnpfs_vnodeops-common.ln: $S/nnpfs/nnpfs_vnodeops-common.c
uvm_amap.o uvm_amap.ln: $S/uvm/uvm_amap.c
uvm_anon.o uvm_anon.ln: $S/uvm/uvm_anon.c
uvm_aobj.o uvm_aobj.ln: $S/uvm/uvm_aobj.c
uvm_device.o uvm_device.ln: $S/uvm/uvm_device.c
uvm_fault.o uvm_fault.ln: $S/uvm/uvm_fault.c
uvm_glue.o uvm_glue.ln: $S/uvm/uvm_glue.c
uvm_init.o uvm_init.ln: $S/uvm/uvm_init.c
uvm_io.o uvm_io.ln: $S/uvm/uvm_io.c
uvm_km.o uvm_km.ln: $S/uvm/uvm_km.c
uvm_map.o uvm_map.ln: $S/uvm/uvm_map.c
uvm_meter.o uvm_meter.ln: $S/uvm/uvm_meter.c
uvm_mmap.o uvm_mmap.ln: $S/uvm/uvm_mmap.c
uvm_object.o uvm_object.ln: $S/uvm/uvm_object.c
uvm_page.o uvm_page.ln: $S/uvm/uvm_page.c
uvm_pager.o uvm_pager.ln: $S/uvm/uvm_pager.c
uvm_pdaemon.o uvm_pdaemon.ln: $S/uvm/uvm_pdaemon.c
uvm_pglist.o uvm_pglist.ln: $S/uvm/uvm_pglist.c
uvm_stat.o uvm_stat.ln: $S/uvm/uvm_stat.c
uvm_swap.o uvm_swap.ln: $S/uvm/uvm_swap.c
uvm_swap_encrypt.o uvm_swap_encrypt.ln: $S/uvm/uvm_swap_encrypt.c
uvm_unix.o uvm_unix.ln: $S/uvm/uvm_unix.c
uvm_user.o uvm_user.ln: $S/uvm/uvm_user.c
uvm_vnode.o uvm_vnode.ln: $S/uvm/uvm_vnode.c
if_gif.o if_gif.ln: $S/net/if_gif.c
ip_ecn.o ip_ecn.ln: $S/netinet/ip_ecn.c
in_gif.o in_gif.ln: $S/netinet/in_gif.c
in6_gif.o in6_gif.ln: $S/netinet6/in6_gif.c
in6_pcb.o in6_pcb.ln: $S/netinet6/in6_pcb.c
in6.o in6.ln: $S/netinet6/in6.c
ip6_divert.o ip6_divert.ln: $S/netinet6/ip6_divert.c
in6_ifattach.o in6_ifattach.ln: $S/netinet6/in6_ifattach.c
in6_cksum.o in6_cksum.ln: $S/netinet6/in6_cksum.c
in6_src.o in6_src.ln: $S/netinet6/in6_src.c
in6_proto.o in6_proto.ln: $S/netinet6/in6_proto.c
dest6.o dest6.ln: $S/netinet6/dest6.c
frag6.o frag6.ln: $S/netinet6/frag6.c
icmp6.o icmp6.ln: $S/netinet6/icmp6.c
ip6_id.o ip6_id.ln: $S/netinet6/ip6_id.c
ip6_input.o ip6_input.ln: $S/netinet6/ip6_input.c
ip6_forward.o ip6_forward.ln: $S/netinet6/ip6_forward.c
ip6_mroute.o ip6_mroute.ln: $S/netinet6/ip6_mroute.c
ip6_output.o ip6_output.ln: $S/netinet6/ip6_output.c
route6.o route6.ln: $S/netinet6/route6.c
mld6.o mld6.ln: $S/netinet6/mld6.c
nd6.o nd6.ln: $S/netinet6/nd6.c
nd6_nbr.o nd6_nbr.ln: $S/netinet6/nd6_nbr.c
nd6_rtr.o nd6_rtr.ln: $S/netinet6/nd6_rtr.c
raw_ip6.o raw_ip6.ln: $S/netinet6/raw_ip6.c
udp6_output.o udp6_output.ln: $S/netinet6/udp6_output.c
pfkey.o pfkey.ln: $S/net/pfkey.c
pfkeyv2.o pfkeyv2.ln: $S/net/pfkeyv2.c
pfkeyv2_parsemessage.o pfkeyv2_parsemessage.ln: $S/net/pfkeyv2_parsemessage.c
pfkeyv2_convert.o pfkeyv2_convert.ln: $S/net/pfkeyv2_convert.c
compat_exec.o compat_exec.ln: $S/compat/common/compat_exec.c
compat_util.o compat_util.ln: $S/compat/common/compat_util.c
compat_dir.o compat_dir.ln: $S/compat/common/compat_dir.c
vfs_syscalls_o43.o vfs_syscalls_o43.ln: $S/compat/common/vfs_syscalls_o43.c
kern_exit_43.o kern_exit_43.ln: $S/compat/common/kern_exit_43.c
kern_info_43.o kern_info_43.ln: $S/compat/common/kern_info_43.c
kern_resource_43.o kern_resource_43.ln: $S/compat/common/kern_resource_43.c
kern_sig_43.o kern_sig_43.ln: $S/compat/common/kern_sig_43.c
tty_43.o tty_43.ln: $S/compat/common/tty_43.c
uipc_syscalls_43.o uipc_syscalls_43.ln: $S/compat/common/uipc_syscalls_43.c
vfs_syscalls_43.o vfs_syscalls_43.ln: $S/compat/common/vfs_syscalls_43.c
vm_43.o vm_43.ln: $S/compat/common/vm_43.c
getsn.o getsn.ln: $S/lib/libkern/getsn.c
random.o random.ln: $S/lib/libkern/random.c
strchr.o strchr.ln: $S/lib/libkern/strchr.c
strrchr.o strrchr.ln: $S/lib/libkern/strrchr.c
__main.o __main.ln: $S/lib/libkern/__main.c
imax.o imax.ln: $S/lib/libkern/imax.c
imin.o imin.ln: $S/lib/libkern/imin.c
lmax.o lmax.ln: $S/lib/libkern/lmax.c
lmin.o lmin.ln: $S/lib/libkern/lmin.c
max.o max.ln: $S/lib/libkern/max.c
min.o min.ln: $S/lib/libkern/min.c
ulmax.o ulmax.ln: $S/lib/libkern/ulmax.c
ulmin.o ulmin.ln: $S/lib/libkern/ulmin.c
memchr.o memchr.ln: $S/lib/libkern/memchr.c
memcmp.o memcmp.ln: $S/lib/libkern/memcmp.c
bcmp.o bcmp.ln: $S/lib/libkern/arch/mips64/bcmp.S
bzero.o bzero.ln: $S/lib/libkern/arch/mips64/bzero.S
bcopy.o bcopy.ln: $S/lib/libkern/arch/mips64/bcopy.S
ovbcopy.o ovbcopy.ln: $S/lib/libkern/arch/mips64/ovbcopy.S
memcpy.o memcpy.ln: $S/lib/libkern/arch/mips64/memcpy.S
memmove.o memmove.ln: $S/lib/libkern/arch/mips64/memmove.S
ffs.o ffs.ln: $S/lib/libkern/arch/mips64/ffs.S
memset.o memset.ln: $S/lib/libkern/memset.c
strcmp.o strcmp.ln: $S/lib/libkern/arch/mips64/strcmp.S
strlcat.o strlcat.ln: $S/lib/libkern/strlcat.c
strlcpy.o strlcpy.ln: $S/lib/libkern/strlcpy.c
strlen.o strlen.ln: $S/lib/libkern/arch/mips64/strlen.S
strncmp.o strncmp.ln: $S/lib/libkern/strncmp.c
strncpy.o strncpy.ln: $S/lib/libkern/strncpy.c
scanc.o scanc.ln: $S/lib/libkern/scanc.c
skpc.o skpc.ln: $S/lib/libkern/skpc.c
htonl.o htonl.ln: $S/lib/libkern/arch/mips64/htonl.S
htons.o htons.ln: $S/lib/libkern/arch/mips64/htons.S
strncasecmp.o strncasecmp.ln: $S/lib/libkern/strncasecmp.c
clock.o clock.ln: $S/arch/mips64/mips64/clock.c
cpu.o cpu.ln: $S/arch/mips64/mips64/cpu.c
interrupt.o interrupt.ln: $S/arch/mips64/mips64/interrupt.c
mem.o mem.ln: $S/arch/mips64/mips64/mem.c
pmap.o pmap.ln: $S/arch/mips64/mips64/pmap.c
process_machdep.o process_machdep.ln: $S/arch/mips64/mips64/process_machdep.c
sendsig.o sendsig.ln: $S/arch/mips64/mips64/sendsig.c
softintr.o softintr.ln: $S/arch/mips64/mips64/softintr.c
sys_machdep.o sys_machdep.ln: $S/arch/mips64/mips64/sys_machdep.c
trap.o trap.ln: $S/arch/mips64/mips64/trap.c
vm_machdep.o vm_machdep.ln: $S/arch/mips64/mips64/vm_machdep.c
cache_loongson2.o cache_loongson2.ln: $S/arch/mips64/mips64/cache_loongson2.S
context.o context.ln: $S/arch/mips64/mips64/context.S
cp0access.o cp0access.ln: $S/arch/mips64/mips64/cp0access.S
exception.o exception.ln: $S/arch/mips64/mips64/exception.S
fp.o fp.ln: $S/arch/mips64/mips64/fp.S
lcore_access.o lcore_access.ln: $S/arch/mips64/mips64/lcore_access.S
lcore_float.o lcore_float.ln: $S/arch/mips64/mips64/lcore_float.S
tlbhandler.o tlbhandler.ln: $S/arch/mips64/mips64/tlbhandler.S
db_disasm.o db_disasm.ln: $S/arch/mips64/mips64/db_disasm.c
db_machdep.o db_machdep.ln: $S/arch/mips64/mips64/db_machdep.c
lcore_ddb.o lcore_ddb.ln: $S/arch/mips64/mips64/lcore_ddb.S
in_cksum.o in_cksum.ln: $S/netinet/in_cksum.c
in4_cksum.o in4_cksum.ln: $S/netinet/in4_cksum.c
cninit.o cninit.ln: $S/dev/cninit.c
autoconf.o autoconf.ln: $S/arch/loongson/loongson/autoconf.c
bus_dma.o bus_dma.ln: $S/arch/loongson/loongson/bus_dma.c
bus_space.o bus_space.ln: $S/arch/loongson/loongson/bus_space.c
conf.o conf.ln: $S/arch/loongson/loongson/conf.c
disksubr.o disksubr.ln: $S/arch/loongson/loongson/disksubr.c
loongson2_machdep.o loongson2_machdep.ln: $S/arch/loongson/loongson/loongson2_machdep.c
machdep.o machdep.ln: $S/arch/loongson/loongson/machdep.c
mutex.o mutex.ln: $S/arch/loongson/loongson/mutex.c
pciide_machdep.o pciide_machdep.ln: $S/arch/loongson/loongson/pciide_machdep.c
pmon.o pmon.ln: $S/arch/loongson/loongson/pmon.c
pmon32.o pmon32.ln: $S/arch/loongson/loongson/pmon32.S
wscons_machdep.o wscons_machdep.ln: $S/arch/loongson/loongson/wscons_machdep.c
wd.o wd.ln: $S/dev/ata/wd.c
ata_wdc.o ata_wdc.ln: $S/dev/ata/ata_wdc.c
ata.o ata.ln: $S/dev/ata/ata.c
atapiscsi.o atapiscsi.ln: $S/dev/atapiscsi/atapiscsi.c
isa.o isa.ln: $S/dev/isa/isa.c
pckbc_isa.o pckbc_isa.ln: $S/dev/isa/pckbc_isa.c
mii.o mii.ln: $S/dev/mii/mii.c
mii_physubr.o mii_physubr.ln: $S/dev/mii/mii_physubr.c
ukphy_subr.o ukphy_subr.ln: $S/dev/mii/ukphy_subr.c
rlphy.o rlphy.ln: $S/dev/mii/rlphy.c
ukphy.o ukphy.ln: $S/dev/mii/ukphy.c
urlphy.o urlphy.ln: $S/dev/mii/urlphy.c
pci.o pci.ln: $S/dev/pci/pci.c
pci_map.o pci_map.ln: $S/dev/pci/pci_map.c
pci_quirks.o pci_quirks.ln: $S/dev/pci/pci_quirks.c
pci_subr.o pci_subr.ln: $S/dev/pci/pci_subr.c
cy82c693.o cy82c693.ln: $S/dev/pci/cy82c693.c
pciide.o pciide.ln: $S/dev/pci/pciide.c
if_rl_pci.o if_rl_pci.ln: $S/dev/pci/if_rl_pci.c
uhci_pci.o uhci_pci.ln: $S/dev/pci/uhci_pci.c
ohci_pci.o ohci_pci.ln: $S/dev/pci/ohci_pci.c
ehci_pci.o ehci_pci.ln: $S/dev/pci/ehci_pci.c
pckbd.o pckbd.ln: $S/dev/pckbc/pckbd.c
wskbdmap_mfii.o wskbdmap_mfii.ln: $S/dev/pckbc/wskbdmap_mfii.c
pms_intelli.o pms_intelli.ln: $S/dev/pckbc/pms_intelli.c
usb.o usb.ln: $S/dev/usb/usb.c
usbdi.o usbdi.ln: $S/dev/usb/usbdi.c
usbdi_util.o usbdi_util.ln: $S/dev/usb/usbdi_util.c
usb_mem.o usb_mem.ln: $S/dev/usb/usb_mem.c
usb_subr.o usb_subr.ln: $S/dev/usb/usb_subr.c
usb_quirks.o usb_quirks.ln: $S/dev/usb/usb_quirks.c
uhub.o uhub.ln: $S/dev/usb/uhub.c
uvideo.o uvideo.ln: $S/dev/usb/uvideo.c
hid.o hid.ln: $S/dev/usb/hid.c
uhidev.o uhidev.ln: $S/dev/usb/uhidev.c
uhid.o uhid.ln: $S/dev/usb/uhid.c
ukbd.o ukbd.ln: $S/dev/usb/ukbd.c
ukbdmap.o ukbdmap.ln: $S/dev/usb/ukbdmap.c
ums.o ums.ln: $S/dev/usb/ums.c
umass.o umass.ln: $S/dev/usb/umass.c
umass_quirks.o umass_quirks.ln: $S/dev/usb/umass_quirks.c
umass_scsi.o umass_scsi.ln: $S/dev/usb/umass_scsi.c
if_url.o if_url.ln: $S/dev/usb/if_url.c
if_urtw.o if_urtw.ln: $S/dev/usb/if_urtw.c
rasops.o rasops.ln: $S/dev/rasops/rasops.c
rasops15.o rasops15.ln: $S/dev/rasops/rasops15.c
wsdisplay.o wsdisplay.ln: $S/dev/wscons/wsdisplay.c
wsevent.o wsevent.ln: $S/dev/wscons/wsevent.c
wskbd.o wskbd.ln: $S/dev/wscons/wskbd.c
wskbdutil.o wskbdutil.ln: $S/dev/wscons/wskbdutil.c
wsmouse.o wsmouse.ln: $S/dev/wscons/wsmouse.c
wsemulconf.o wsemulconf.ln: $S/dev/wscons/wsemulconf.c
wsemul_vt100.o wsemul_vt100.ln: $S/dev/wscons/wsemul_vt100.c
wsemul_vt100_subr.o wsemul_vt100_subr.ln: $S/dev/wscons/wsemul_vt100_subr.c
wsemul_vt100_chars.o wsemul_vt100_chars.ln: $S/dev/wscons/wsemul_vt100_chars.c
wsemul_vt100_keys.o wsemul_vt100_keys.ln: $S/dev/wscons/wsemul_vt100_keys.c
wsfont.o wsfont.ln: $S/dev/wsfont/wsfont.c
scsi_base.o scsi_base.ln: $S/scsi/scsi_base.c
scsi_ioctl.o scsi_ioctl.ln: $S/scsi/scsi_ioctl.c
scsiconf.o scsiconf.ln: $S/scsi/scsiconf.c
cd.o cd.ln: $S/scsi/cd.c
ch.o ch.ln: $S/scsi/ch.c
sd.o sd.ln: $S/scsi/sd.c
st.o st.ln: $S/scsi/st.c
ss.o ss.ln: $S/scsi/ss.c
ss_mustek.o ss_mustek.ln: $S/scsi/ss_mustek.c
ss_scanjet.o ss_scanjet.ln: $S/scsi/ss_scanjet.c
uk.o uk.ln: $S/scsi/uk.c
mainbus.o mainbus.ln: $S/arch/loongson/dev/mainbus.c
bonito.o bonito.ln: $S/arch/loongson/dev/bonito.c
glx.o glx.ln: $S/arch/loongson/dev/glx.c
glxpcib.o glxpcib.ln: $S/arch/loongson/dev/glxpcib.c
pcib.o pcib.ln: $S/arch/loongson/dev/pcib.c
mcclock.o mcclock.ln: $S/arch/loongson/dev/mcclock.c
mcclock_isa.o mcclock_isa.ln: $S/arch/loongson/dev/mcclock_isa.c
smfb.o smfb.ln: $S/arch/loongson/dev/smfb.c
