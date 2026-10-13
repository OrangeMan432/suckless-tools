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

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",       STRING,  &colorname[INIT] },
		{ "color4",       STRING,  &colorname[INPUT] },
		{ "color1",       STRING,  &colorname[FAILED] },
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
