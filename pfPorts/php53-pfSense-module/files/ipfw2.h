/*
 * Copyright (c) 2002-2003 Luigi Rizzo
 * Copyright (c) 1996 Alex Nash, Paul Traina, Poul-Henning Kamp
 * Copyright (c) 1994 Ugen J.S.Antsilevich
 *
 * Idea and grammar partially left from:
 * Copyright (c) 1993 Daniel Boulet
 *
 * Redistribution and use in source forms, with and without modification,
 * are permitted provided that this entire comment appears intact.
 *
 * Redistribution in binary form may occur without any restrictions.
 * Obviously, it would be nice if you gave credit where credit is due
 * but requiring it would be too onerous.
 *
 * This software is provided ``AS IS'' without any warranties of any kind.
 *
 * NEW command line interface for IP firewall facility
 *
 * $FreeBSD: src/sbin/ipfw/ipfw2.h,v 1.9.2.2.2.1 2010/06/14 02:09:06 kensmith Exp $
 */

/*
 * _s_x is a structure that stores a string <-> token pairs, used in
 * various places in the parser. Entries are stored in arrays,
 * with an entry with s=NULL as terminator.
 * The search routines are match_token() and match_value().
 * Often, an element with x=0 contains an error string.
 *
 */
struct _s_x {
	char const *s;
	int x;
};

enum tokens {
	TOK_NULL=0,

	TOK_OR,
	TOK_NOT,
	TOK_STARTBRACE,
	TOK_ENDBRACE,

	TOK_ACCEPT,
	TOK_COUNT,
	TOK_PIPE,
	TOK_LINK,
	TOK_QUEUE,
	TOK_FLOWSET,
	TOK_SCHED,
	TOK_DIVERT,
	TOK_TEE,
	TOK_NETGRAPH,
	TOK_NGTEE,
	TOK_FORWARD,
	TOK_SKIPTO,
	TOK_DENY,
	TOK_REJECT,
	TOK_RESET,
	TOK_UNREACH,
	TOK_CHECKSTATE,
	TOK_NAT,
	TOK_REASS,

	TOK_ALTQ,
	TOK_LOG,
	TOK_TAG,
	TOK_UNTAG,

	TOK_TAGGED,
	TOK_UID,
	TOK_GID,
	TOK_JAIL,
	TOK_IN,
	TOK_LIMIT,
	TOK_KEEPSTATE,
	TOK_LAYER2,
	TOK_OUT,
	TOK_DIVERTED,
	TOK_DIVERTEDLOOPBACK,
	TOK_DIVERTEDOUTPUT,
	TOK_XMIT,
	TOK_RECV,
	TOK_VIA,
	TOK_FRAG,
	TOK_IPOPTS,
	TOK_IPLEN,
	TOK_IPID,
	TOK_IPPRECEDENCE,
	TOK_DSCP,
	TOK_IPTOS,
	TOK_IPTTL,
	TOK_IPVER,
	TOK_ESTAB,
	TOK_SETUP,
	TOK_TCPDATALEN,
	TOK_TCPFLAGS,
	TOK_TCPOPTS,
	TOK_TCPSEQ,
	TOK_TCPACK,
	TOK_TCPWIN,
	TOK_ICMPTYPES,
	TOK_MAC,
	TOK_MACTYPE,
	TOK_VERREVPATH,
	TOK_VERSRCREACH,
	TOK_ANTISPOOF,
	TOK_IPSEC,
	TOK_COMMENT,

	TOK_PLR,
	TOK_NOERROR,
	TOK_BUCKETS,
	TOK_DSTIP,
	TOK_SRCIP,
	TOK_DSTPORT,
	TOK_SRCPORT,
	TOK_ALL,
	TOK_MASK,
	TOK_FLOW_MASK,
	TOK_SCHED_MASK,
	TOK_BW,
	TOK_DELAY,
	TOK_PROFILE,
	TOK_BURST,
	TOK_RED,
	TOK_GRED,
	TOK_DROPTAIL,
	TOK_PROTO,
	/* dummynet tokens */
	TOK_WEIGHT,
	TOK_LMAX,
	TOK_PRI,
	TOK_TYPE,
	TOK_SLOTSIZE,

	TOK_IP,
	TOK_IF,
 	TOK_ALOG,
 	TOK_DENY_INC,
 	TOK_SAME_PORTS,
 	TOK_UNREG_ONLY,
 	TOK_RESET_ADDR,
 	TOK_ALIAS_REV,
 	TOK_PROXY_ONLY,
	TOK_REDIR_ADDR,
	TOK_REDIR_PORT,
	TOK_REDIR_PROTO,	

	TOK_IPV6,
	TOK_FLOWID,
	TOK_ICMP6TYPES,
	TOK_EXT6HDR,
	TOK_DSTIP6,
	TOK_SRCIP6,

	TOK_IPV4,
	TOK_UNREACH6,
	TOK_RESET6,

	TOK_FIB,
	TOK_SETFIB,
	TOK_LOOKUP,
};
