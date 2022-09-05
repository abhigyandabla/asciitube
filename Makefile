# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  gentobe_config = debug

else ifeq ($(config),release)
  gentobe_config = release

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := gentobe

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

gentobe:
ifneq (,$(gentobe_config))
	@echo "==== Building gentobe ($(gentobe_config)) ===="
	@${MAKE} --no-print-directory -C . -f gentobe.make config=$(gentobe_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f gentobe.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   gentobe"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"