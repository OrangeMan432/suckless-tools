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
         dmenu-04-local-xresources.diff
         dmenu-05-local-alpha.diff
         slock-config.h
         slock-01-local-xresources.diff
         tabbed-config.h
         tabbed-01-local-xresources.diff
         tabbed-02-local-alpha.diff)
sha256sums=('29cf5354651547eea9aa76c9fe49afbbb10dbcaaffa895ebea5a1426b9f05bf5'
            '5223e51f9e01989a769ab4343dd287a47c831ee5d6d8c845d3e68dc477ca0d18'
            '4f71d910c3b44c909fc599ff3d5a9216d029561138efd52e8fdb156198ae6a39'
            '31f0c7a981137428593e4719d65bd73318666cf6c0b8a0466be41454f50385b9'
            '4420b35be15e1609999a8f17add022f6c71368da6d9f3ea425cd706e7acfcb02'
            '06f038e47b6b8d0d18a7b1657a2e62a2d9dab48270ab6520d839d54372bd417b'
            '37312905cbc97470bcf2e38720b999e53dd251efd32cc84c47fcf029ae996b12'
            'f1a2db4d1d4026b2e2b9b69ab9247ad2aeea9cfcb86836f67a3e1563b124a09a'
            '5c45962472d0c1dfbf682985902526deeb550b9ba83aba93577c551ad356dfe4'
            '35a110a6a2faaa8801354dad2b64ccd623b690eaeeaef519d470f09c76ea65c0'
            'a6bff09636e87f5039a4d3c571e1c02e2766a6abae6cbcd5f5d2cc98bc120290'
            '2a51a55de6a8baf64d26dd8d5270131c262f58e9b095da481df3fb32e0bcd685'
            'a6c20e0efc52e11c2d9903aac205c3624cbf3c4eab97e62e189f77229173d57a'
            '608c1893b9c6fd89b9ff9a401d9b30cdeb0164660d9c098e04bdcf9835496e78')

_dmenu_patches=(dmenu-01-local-border-center.diff
                dmenu-02-local-vi-mode.diff
                dmenu-03-local-password.diff
                dmenu-04-local-xresources.diff
                dmenu-05-local-alpha.diff)
_slock_patches=(slock-01-local-xresources.diff)
_tabbed_patches=(tabbed-01-local-xresources.diff
                tabbed-02-local-alpha.diff)

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
  for p in "${_slock_patches[@]}"; do
    echo "=> $p"
    patch -p1 < ../$p || return 1
  done
  cp ../slock-config.h config.h
  make PREFIX=/usr

  cd $srcdir/tabbed
  for p in "${_tabbed_patches[@]}"; do
    echo "=> $p"
    patch -p1 < ../$p || return 1
  done
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
