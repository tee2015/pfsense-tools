--- cache.c.orig	2007-11-07 00:34:18.000000000 -0600
+++ cache.c	2013-06-23 06:23:03.000000000 -0500
@@ -118,12 +118,21 @@
 
 	cache_size--;
 
+#ifdef HAVE_PFSYNC_STATE
+#if __FreeBSD_version > 1000000
+	ent->id = st->id;
+#else
+	ent->id[0] = st->id[0];
+	ent->id[1] = st->id[1];
+#endif
+#else
 	ent->addr[0] = st->lan.addr;
 	ent->port[0] = st->lan.port;
 	ent->addr[1] = st->ext.addr;
 	ent->port[1] = st->ext.port;
 	ent->af = st->af;
 	ent->proto = st->proto;
+#endif
 #ifdef HAVE_INOUT_COUNT
 	ent->bytes = COUNTER(st->bytes[0]) + COUNTER(st->bytes[1]);
 #else
@@ -147,13 +156,21 @@
 	if (cache_max == 0)
 		return (NULL);
 
+#ifdef HAVE_PFSYNC_STATE
+#if __FreeBSD_version > 1000000
+	ent.id = st->id;
+#else
+	ent.id[0] = st->id[0];
+	ent.id[1] = st->id[1];
+#endif
+#else
 	ent.addr[0] = st->lan.addr;
 	ent.port[0] = st->lan.port;
 	ent.addr[1] = st->ext.addr;
 	ent.port[1] = st->ext.port;
 	ent.af = st->af;
 	ent.proto = st->proto;
-
+#endif
 	old = RB_FIND(sc_tree, &sctree, &ent);
 
 	if (old == NULL) {
@@ -210,8 +227,25 @@
 static __inline int
 sc_cmp(struct sc_ent *a, struct sc_ent *b)
 {
+#ifdef HAVE_PFSYNC_STATE
+#if __FreeBSD_version > 1000000
+	if (a->id > b->id)
+		return (1);
+	if (a->id < b->id)
+		return (-1);
+#else
+	if (a->id[0] > b->id[0])
+		return (1);
+	if (a->id[0] < b->id[0])
+		return (-1);
+	if (a->id[1] > b->id[1])
+		return (1);
+	if (a->id[1] < b->id[1])
+		return (-1);
+#endif
+#else	
        	int diff;
-	
+
 	if ((diff = a->proto - b->proto) != 0)
 		return (diff);
 	if ((diff = a->af - b->af) != 0)
@@ -269,6 +303,6 @@
 		return (diff);
 	if ((diff = a->port[1] - b->port[1]) != 0)
 		return (diff);
-
+#endif
 	return (0);
 }
