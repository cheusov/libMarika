PROGS      = \
   set4S set8S set4U set8U \
   setI setU setL setLU \
   \
   map4U8U map4U4U map8U4U map8U8U \
   map4U8S map4U4S map8U4S map8U8S \
   map4S8U map4S4U map8S4U map8S8U \
   map4S8S map4S4S map8S4S map8S8S \
   \
   mapIUIU mapIUIS mapISIU mapISIS \
   mapLUIU mapLUIS mapLSIU mapLSIS \
   mapIULU mapIULS mapISLU mapISLS \
   mapLULU mapLULS mapLSLU mapLSLS \
   \
   map4SP map4UP map8SP map8UP \
   mapIP mapUP mapLP mapLUP

PROGS +=	example_IP

MKC_FEATURES +=	macro

CLEANFILES += \
   set4S.c set8S.c set4U.c set8U.c \
   setI.c setU.c setL.c setLU.c \
   \
   map4U8U.c map4U4U.c map8U4U.c map8U8U.c \
   map4U8S.c map4U4S.c map8U4S.c map8U8S.c \
   map4S8U.c map4S4U.c map8S4U.c map8S8U.c \
   map4S8S.c map4S4S.c map8S4S.c map8S8S.c \
   \
   mapIULU.c mapIUIU.c mapLUIU.c mapLULU.c \
   mapIULS.c mapIUIS.c mapLUIS.c mapLULS.c \
   mapISLU.c mapISIU.c mapLSIU.c mapLSLU.c \
   mapISLS.c mapISIS.c mapLSIS.c mapLSLS.c \
   \
   map4SP.c map4UP.c map8SP.c map8UP.c \
   mapIP.c mapUP.c mapLP.c mapLUP.c

replace_digits =	awk '{ sub(/[0-9][0-9][0-9][0-9][0-9][0-9]*/, "DIIIIGITS"); } {print}'

#
set4S.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/int32_t/g' -e 's/FUNC_PREF/mar4S/g' -e 's/FMT/PRId32/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

set8S.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/int64_t/g' -e 's/FUNC_PREF/mar8S/g' -e 's/FMT/PRId64/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

set4U.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar4U/g' -e 's/FMT/PRIu32/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

set8U.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar8U/g' -e 's/FMT/PRIu64/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

setI.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/int/g' -e 's/FUNC_PREF/marI/g' -e 's/FMT/"d"/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

setU.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/unsigned/g' -e 's/FUNC_PREF/marU/g' -e 's/FMT/"u"/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

setL.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/long/g' -e 's/FUNC_PREF/marL/g' -e 's/FMT/"ld"/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

setLU.c: set_template.int.c
	set -e; \
	sed -e 's/ITEM_TYPE/unsigned long/g' -e 's/FUNC_PREF/marLU/g' -e 's/FMT/"lu"/g' set_template.int.c > $@.tmp; \
	mv $@.tmp $@

#
map4U8U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint32_t/g' -e 's/VALUE_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar4U8U/g' -e 's/FMT_KEY/PRIu32/g' -e 's/FMT_VALUE/PRIu64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4U4U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint32_t/g' -e 's/VALUE_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar4U4U/g' -e 's/FMT_KEY/PRIu32/g' -e 's/FMT_VALUE/PRIu32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8U4U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint64_t/g' -e 's/VALUE_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar8U4U/g' -e 's/FMT_KEY/PRIu64/g' -e 's/FMT_VALUE/PRIu32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8U8U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint64_t/g' -e 's/VALUE_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar8U8U/g' -e 's/FMT_KEY/PRIu64/g' -e 's/FMT_VALUE/PRIu64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4U8S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint32_t/g' -e 's/VALUE_TYPE/int64_t/g' -e 's/FUNC_PREF/mar4U8S/g' -e 's/FMT_KEY/PRIu32/g' -e 's/FMT_VALUE/PRId64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4U4S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint32_t/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/mar4U4S/g' -e 's/FMT_KEY/PRIu32/g' -e 's/FMT_VALUE/PRId32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8U4S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint64_t/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/mar8U4S/g' -e 's/FMT_KEY/PRIu64/g' -e 's/FMT_VALUE/PRId32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8U8S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/uint64_t/g' -e 's/VALUE_TYPE/int64_t/g' -e 's/FUNC_PREF/mar8U8S/g' -e 's/FMT_KEY/PRIu64/g' -e 's/FMT_VALUE/PRId64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

#
map4S8U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int32_t/g' -e 's/VALUE_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar4S8U/g' -e 's/FMT_KEY/PRId32/g' -e 's/FMT_VALUE/PRIu64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4S4U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int32_t/g' -e 's/VALUE_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar4S4U/g' -e 's/FMT_KEY/PRId32/g' -e 's/FMT_VALUE/PRIu32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8S4U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int64_t/g' -e 's/VALUE_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar8S4U/g' -e 's/FMT_KEY/PRId64/g' -e 's/FMT_VALUE/PRIu32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8S8U.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int64_t/g' -e 's/VALUE_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar8S8U/g' -e 's/FMT_KEY/PRId64/g' -e 's/FMT_VALUE/PRIu64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4S8S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int32_t/g' -e 's/VALUE_TYPE/int64_t/g' -e 's/FUNC_PREF/mar4S8S/g' -e 's/FMT_KEY/PRId32/g' -e 's/FMT_VALUE/PRId64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map4S4S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int32_t/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/mar4S4S/g' -e 's/FMT_KEY/PRId32/g' -e 's/FMT_VALUE/PRId32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8S4S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int64_t/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/mar8S4S/g' -e 's/FMT_KEY/PRId64/g' -e 's/FMT_VALUE/PRId32/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

map8S8S.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int64_t/g' -e 's/VALUE_TYPE/int64_t/g' -e 's/FUNC_PREF/mar8S8S/g' -e 's/FMT_KEY/PRId64/g' -e 's/FMT_VALUE/PRId64/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

#
mapIULU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned/g' -e 's/VALUE_TYPE/unsigned long/g' -e 's/FUNC_PREF/marIULU/g' -e 's/FMT_KEY/"u"/g' -e 's/FMT_VALUE/"lu"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapIUIU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned/g' -e 's/VALUE_TYPE/unsigned/g' -e 's/FUNC_PREF/marIUIU/g' -e 's/FMT_KEY/"u"/g' -e 's/FMT_VALUE/"u"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLUIU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned long/g' -e 's/VALUE_TYPE/unsigned/g' -e 's/FUNC_PREF/marLUIU/g' -e 's/FMT_KEY/"lu"/g' -e 's/FMT_VALUE/"u"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLULU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned long/g' -e 's/VALUE_TYPE/unsigned long/g' -e 's/FUNC_PREF/marLULU/g' -e 's/FMT_KEY/"lu"/g' -e 's/FMT_VALUE/"lu"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapIULS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned/g' -e 's/VALUE_TYPE/long/g' -e 's/FUNC_PREF/marIULS/g' -e 's/FMT_KEY/"u"/g' -e 's/FMT_VALUE/"ld"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapIUIS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/marIUIS/g' -e 's/FMT_KEY/"u"/g' -e 's/FMT_VALUE/"d"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLUIS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned long/g' -e 's/VALUE_TYPE/int32_t/g' -e 's/FUNC_PREF/marLUIS/g' -e 's/FMT_KEY/"lu"/g' -e 's/FMT_VALUE/"d"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLULS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned long/g' -e 's/VALUE_TYPE/long/g' -e 's/FUNC_PREF/marLULS/g' -e 's/FMT_KEY/"lu"/g' -e 's/FMT_VALUE/"ld"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

#
mapISLU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int/g' -e 's/VALUE_TYPE/unsigned long/g' -e 's/FUNC_PREF/marISLU/g' -e 's/FMT_KEY/"d"/g' -e 's/FMT_VALUE/"lu"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapISIU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int/g' -e 's/VALUE_TYPE/unsigned/g' -e 's/FUNC_PREF/marISIU/g' -e 's/FMT_KEY/"d"/g' -e 's/FMT_VALUE/"u"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLSIU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/long/g' -e 's/VALUE_TYPE/unsigned/g' -e 's/FUNC_PREF/marLSIU/g' -e 's/FMT_KEY/"ld"/g' -e 's/FMT_VALUE/"u"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLSLU.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/long/g' -e 's/VALUE_TYPE/unsigned long/g' -e 's/FUNC_PREF/marLSLU/g' -e 's/FMT_KEY/"ld"/g' -e 's/FMT_VALUE/"lu"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapISLS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int/g' -e 's/VALUE_TYPE/long/g' -e 's/FUNC_PREF/marISLS/g' -e 's/FMT_KEY/"d"/g' -e 's/FMT_VALUE/"ld"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapISIS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/int/g' -e 's/VALUE_TYPE/int/g' -e 's/FUNC_PREF/marISIS/g' -e 's/FMT_KEY/"d"/g' -e 's/FMT_VALUE/"d"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLSIS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/long/g' -e 's/VALUE_TYPE/int/g' -e 's/FUNC_PREF/marLSIS/g' -e 's/FMT_KEY/"ld"/g' -e 's/FMT_VALUE/"d"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

mapLSLS.c: map_template.int.c
	set -e; \
	sed -e 's/KEY_TYPE/long/g' -e 's/VALUE_TYPE/long/g' -e 's/FUNC_PREF/marLSLS/g' -e 's/FMT_KEY/"ld"/g' -e 's/FMT_VALUE/"ld"/g' map_template.int.c > $@.tmp; \
	mv $@.tmp $@

#
map4SP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/int32_t/g' -e 's/FUNC_PREF/mar4S/g' -e 's/FMT_KEY/PRId32/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

map4UP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/uint32_t/g' -e 's/FUNC_PREF/mar4U/g' -e 's/FMT_KEY/PRIu32/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

map8SP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/int64_t/g' -e 's/FUNC_PREF/mar8S/g' -e 's/FMT_KEY/PRId64/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

map8UP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/uint64_t/g' -e 's/FUNC_PREF/mar8U/g' -e 's/FMT_KEY/PRIu64/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

#
mapIP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/int/g' -e 's/FUNC_PREF/marI/g' -e 's/FMT_KEY/"d"/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

mapUP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned/g' -e 's/FUNC_PREF/marU/g' -e 's/FMT_KEY/"u"/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

mapLP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/long/g' -e 's/FUNC_PREF/marL/g' -e 's/FMT_KEY/"ld"/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

mapLUP.c: map_template.ptr.c
	set -e; \
	sed -e 's/KEY_TYPE/unsigned long/g' -e 's/FUNC_PREF/marLU/g' -e 's/FMT_KEY/"lu"/g' map_template.ptr.c > $@.tmp; \
	mv $@.tmp $@

#
.PHONY : test_output
test_output:
	@${ld_lib_path}; \
	{ \
	echo 'set*, map*' 1>&2; \
	echo ============================= set4S =============================; \
	${OBJDIR_examples}/set4S; \
	echo ============================= set8S =============================; \
	${OBJDIR_examples}/set8S; \
	echo ============================= set4U =============================; \
	${OBJDIR_examples}/set4U; \
	echo ============================= set8U =============================; \
	${OBJDIR_examples}/set8U; \
	\
	{ \
	  echo ============================= setI =============================; \
	  ${OBJDIR_examples}/setI; \
	  echo ============================= setU =============================; \
	  ${OBJDIR_examples}/setU; \
	  echo ============================= setL =============================; \
	  ${OBJDIR_examples}/setL; \
	  echo ============================= setLU =============================; \
	  ${OBJDIR_examples}/setLU; \
	} | ${replace_digits}; \
	\
	echo ============================= map4U8U =============================; \
	${OBJDIR_examples}/map4U8U; \
	echo ============================= map4U4U =============================; \
	${OBJDIR_examples}/map4U4U; \
	echo ============================= map8U4U =============================; \
	${OBJDIR_examples}/map8U4U; \
	echo ============================= map8U8U =============================; \
	${OBJDIR_examples}/map8U8U; \
	\
	echo ============================= map4U4S =============================; \
	${OBJDIR_examples}/map4U4S; \
	echo ============================= map4U8S =============================; \
	${OBJDIR_examples}/map4U8S; \
	echo ============================= map8U4S =============================; \
	${OBJDIR_examples}/map8U4S; \
	echo ============================= map8U8S =============================; \
	${OBJDIR_examples}/map8U8S; \
	\
	echo ============================= map4S4U =============================; \
	${OBJDIR_examples}/map4S4U; \
	echo ============================= map4S8U =============================; \
	${OBJDIR_examples}/map4S8U; \
	echo ============================= map8S4U =============================; \
	${OBJDIR_examples}/map8S4U; \
	echo ============================= map8S8U =============================; \
	${OBJDIR_examples}/map8S8U; \
	\
	echo ============================= map4S4S =============================; \
	${OBJDIR_examples}/map4S4S; \
	echo ============================= map4S8S =============================; \
	${OBJDIR_examples}/map4S8S; \
	echo ============================= map8S4S =============================; \
	${OBJDIR_examples}/map8S4S; \
	echo ============================= map8S8S =============================; \
	${OBJDIR_examples}/map8S8S; \
	\
	{ \
	  echo ============================= mapIULU =============================; \
	  ${OBJDIR_examples}/mapIULU; \
	  echo ============================= mapIUIU =============================; \
	  ${OBJDIR_examples}/mapIUIU; \
	  echo ============================= mapLUIU =============================; \
	  ${OBJDIR_examples}/mapLUIU; \
	  echo ============================= mapLULU =============================; \
	  ${OBJDIR_examples}/mapLULU; \
	  \
	  echo ============================= mapIUIS =============================; \
	  ${OBJDIR_examples}/mapIUIS; \
	  echo ============================= mapIULS =============================; \
	  ${OBJDIR_examples}/mapIULS; \
	  echo ============================= mapLUIS =============================; \
	  ${OBJDIR_examples}/mapLUIS; \
	  echo ============================= mapLULS =============================; \
	  ${OBJDIR_examples}/mapLULS; \
	  \
	  echo ============================= mapISIU =============================; \
	  ${OBJDIR_examples}/mapISIU; \
	  echo ============================= mapISLU =============================; \
	  ${OBJDIR_examples}/mapISLU; \
	  echo ============================= mapLSIU =============================; \
	  ${OBJDIR_examples}/mapLSIU; \
	  echo ============================= mapLSLU =============================; \
	  ${OBJDIR_examples}/mapLSLU; \
	  \
	  echo ============================= mapISIS =============================; \
	  ${OBJDIR_examples}/mapISIS; \
	  echo ============================= mapISLS =============================; \
	  ${OBJDIR_examples}/mapISLS; \
	  echo ============================= mapLSIS =============================; \
	  ${OBJDIR_examples}/mapLSIS; \
	  echo ============================= mapLSLS =============================; \
	  ${OBJDIR_examples}/mapLSLS; \
	} | ${replace_digits}; \
	\
	echo ============================= map4SP =============================; \
	${OBJDIR_examples}/map4SP; \
	echo ============================= map4UP =============================; \
	${OBJDIR_examples}/map4UP; \
	echo ============================= map8SP =============================; \
	${OBJDIR_examples}/map8SP; \
	echo ============================= map8UP =============================; \
	${OBJDIR_examples}/map8UP; \
	{ \
	  echo ============================= mapIP =============================; \
	  ${OBJDIR_examples}/mapIP; \
	  echo ============================= mapUP =============================; \
	  ${OBJDIR_examples}/mapUP; \
	  echo ============================= mapLP =============================; \
	  ${OBJDIR_examples}/mapLP; \
	  echo ============================= mapLUP =============================; \
	  ${OBJDIR_examples}/mapLUP; \
	} | ${replace_digits}; \
	} | sed -e 's/(nil)/0x0/'


.include <mkc.minitest.mk>
.include <mkc.mk>
