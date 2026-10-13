/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* dwm theme: single source of truth, from the sibling dwm-pkgbuild repo */
#include "../dwm-pkgbuild/colors.h"

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                    /* minimum width when centered */
static const float menu_height_ratio = 4.0f;  /* This is the ratio used in the original calculation */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"JetBrainsMono Nerd Font:size=16"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { col_fg1, col_gray1 },
	[SchemeSel] = { col_fg1, col_bg2 },
	[SchemeOut] = { col_gray1, col_fg1 },
	[SchemeCursor] = { col_gray1, col_fg1 },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* X resources to load at startup */
static const XResPref resources[] = {
	/* name                  type     address */
	{ "dmenu.font",          STRING,  &fonts[0] },
	{ "dmenu.prompt",        STRING,  &prompt },
	{ "dmenu.foreground",    STRING,  &colors[SchemeNorm][ColFg] },
	{ "dmenu.background",    STRING,  &colors[SchemeNorm][ColBg] },
	{ "dmenu.foregroundSel", STRING,  &colors[SchemeSel][ColFg] },
	{ "dmenu.backgroundSel", STRING,  &colors[SchemeSel][ColBg] },
	{ "dmenu.foregroundOut", STRING,  &colors[SchemeOut][ColFg] },
	{ "dmenu.backgroundOut", STRING,  &colors[SchemeOut][ColBg] },
	{ "dmenu.topbar",        INTEGER, &topbar },
	{ "dmenu.lines",         INTEGER, &lines },
};

/*
 * -vi option; if nonzero, vi mode is always enabled and can be
 * accessed with the global_esc keysym + mod mask
 */
static unsigned int vi_mode = 1;
static unsigned int start_mode = 0;			/* mode to use when -vi is passed. 0 = insert mode, 1 = normal mode */
static Key global_esc = { XK_n, Mod1Mask };	/* escape key when vi mode is not enabled explicitly */
static Key quit_keys[] = {
	/* keysym	modifier */
	{ XK_q,		0 }
};

/* Size of the window border */
static unsigned int border_width = 0;
