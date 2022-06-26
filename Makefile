BUILDDIR=builddir

test: all
	meson test -C $(BUILDDIR)

coverage: test
	ninja -C $(BUILDDIR) coverage

clean:
	rm -rf $(BUILDDIR)

scan-build: all
	ninja -C $(BUILDDIR) scan-build

all:
	meson $(BUILDDIR) && meson compile -C $(BUILDDIR)
