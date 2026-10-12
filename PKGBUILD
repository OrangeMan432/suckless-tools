pkgname=suckless-tools
pkgver=20261012
pkgrel=1
pkgdesc="Patched dmenu, slock and tabbed builds sharing dwm's theme"
arch=('i686' 'x86_64' 'aarch64')
license=('MIT')
depends=('libx11' 'libxext' 'libxft' 'libxinerama' 'libxrandr'
         'fontconfig' 'libxcrypt')
provides=('dmenu' 'slock' 'tabbed')
conflicts=('dmenu' 'slock' 'tabbed')
source=(dmenu::git+https://git.suckless.org/dmenu#commit=7175c4880bac3d2a2d4a6262b59193f0a38e2fdb
        slock::git+https://git.suckless.org/slock#commit=3791a996e230aec59d61faea46634ae4f031e359
        tabbed::git+https://git.suckless.org/tabbed#commit=e65146d2918e0072fc09b3dfb06785e170787164
        dmenu-config.h
        dmenu-01-local-border-center.diff
        dmenu-02-local-vi-mode.diff
        dmenu-03-local-password.diff
        slock-config.h
        tabbed-config.h)
sha256sums=('29cf5354651547eea9aa76c9fe49afbbb10dbcaaffa895ebea5a1426b9f05bf5'
            '5223e51f9e01989a769ab4343dd287a47c831ee5d6d8c845d3e68dc477ca0d18'
            '4f71d910c3b44c909fc599ff3d5a9216d029561138efd52e8fdb156198ae6a39'
            '72b5e790d479d6762fb2f0013e1c8b06955eff1ad4fe2a42782e3b16a01d956f'
            '4420b35be15e1609999a8f17add022f6c71368da6d9f3ea425cd706e7acfcb02'
            '06f038e47b6b8d0d18a7b1657a2e62a2d9dab48270ab6520d839d54372bd417b'
            '37312905cbc97470bcf2e38720b999e53dd251efd32cc84c47fcf029ae996b12'
            'bd72eafd5c472bca32f45719f6c7a27c6136848cbeb88fe1cc2f2985d62005cd'
            '7c8a12cf002b8a64092e93854aa4bf094b4cf05abc95da10f6835d9d52cda83d')

_dmenu_patches=(dmenu-01-local-border-center.diff
                dmenu-02-local-vi-mode.diff
                dmenu-03-local-password.diff)

build() {
  # configs include ../dwm-pkgbuild/colors.h: resolve the sibling repo
  # inside srcdir (no usernames or absolute paths in the C sources).
  ln -sfn "$(dirname "$startdir")/dwm-pkgbuild" "$srcdir/dwm-pkgbuild"
  cd $srcdir/dmenu
  for p in "${_dmenu_patches[@]}"; do
    echo "=> $p"
    patch -p1 < ../$p || return 1
  done
  cp ../dmenu-config.h config.h
  make PREFIX=/usr

  cd $srcdir/slock
  cp ../slock-config.h config.h
  make PREFIX=/usr

  cd $srcdir/tabbed
  cp ../tabbed-config.h config.h
  make PREFIX=/usr
}

package() {
  make -C $srcdir/dmenu PREFIX=/usr DESTDIR=$pkgdir install
  make -C $srcdir/slock PREFIX=/usr DESTDIR=$pkgdir install
  make -C $srcdir/tabbed PREFIX=/usr DESTDIR=$pkgdir install
  install -Dm644 $srcdir/dmenu/LICENSE $pkgdir/usr/share/licenses/$pkgname/dmenu.LICENSE
  install -Dm644 $srcdir/slock/LICENSE $pkgdir/usr/share/licenses/$pkgname/slock.LICENSE
  install -Dm644 $srcdir/tabbed/LICENSE $pkgdir/usr/share/licenses/$pkgname/tabbed.LICENSE
}
