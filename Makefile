
SUBDIRS:= core core_mt tinyxml server server_mt client luaclient test test_mt

all: $(SUBDIRS)
	@for dir in $(SUBDIRS); do make -C $$dir || exit"$$?"; done

clean: $(SUBDIRS)
	@for dir in $(SUBDIRS); do make -C $$dir clean; done
