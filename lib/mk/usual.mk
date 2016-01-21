
# libusual sources, for embedded usage
USUAL_DIR ?= .

VPATH += $(USUAL_DIR)

ifneq ($(srcdir),$(builddir))
VPATH += $(call JoinPath,$(srcdir),$(USUAL_DIR))
endif

##
## Utility functions for libusual link
##

_USUAL_DIR = $(call JoinPath,$(srcdir),$(USUAL_DIR))

# module names from sources (plus headers)
UsualMods = $(trace1)$(shell $(_USUAL_DIR)/find_modules.sh $(_USUAL_DIR) $(wildcard $(addprefix $(srcdir)/,$(1))))

# full-path sources based on module list
UsualSrcsFull = $(trace1)$(wildcard $(addprefix $(_USUAL_DIR)/usual/,$(addsuffix *.[ch],$(1))))

# remove USUAL_DIR
UsualStrip = $(trace1)$(subst $(_USUAL_DIR)/,,$(1))

# simple-path sources based on module list
UsualSrcs = $(call UsualStrip,$(call UsualSrcsFull,$(1)))

# objs with objdir from source file list (1-cleantgt, 2-src list)
UsualObjs = $(call SourceObjs,$(1),$(call UsualSrcs,$(call UsualMods,$(2))))

# usual sources from user source file list
UsualSources = $(call UsualSrcsFull,$(call UsualMods,$(1)))

# embed libusual objects directly
$(1)_USUAL_SRCS = $$(call UsualSources,$$($(1)_ALLSRCS))
$(1)_OBJS += $$(call UsualObjs,$(1),$$($(1)_SOURCES) $$(nodist_$(1)_SOURCES))
$(1)_CPPFLAGS += -I$$(USUAL_DIR)


