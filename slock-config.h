/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

/* dwm theme: single source of truth, from the sibling dwm-pkgbuild repo */
#include "../dwm-pkgbuild/colors.h"

static const char *colorname[NUMCOLS] = {
	[INIT] =   col_gray1,     /* after initialization */
	[INPUT] =  col_bg2,       /* during input */
	[FAILED] = col_gray1,     /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
