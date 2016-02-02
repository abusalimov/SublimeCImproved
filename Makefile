all:  # the default Make task


SRC_YAML    := src/c-improved.syntax.yaml
DEST_PLIST  := C\ Improved.tmLanguage

SYNTAXDEV   := node_modules/.bin/syntaxdev


.PHONY: all release devenv

all: release

release .PHONY: $(DEST_PLIST)  # .PHONY: rebuild unconditionally

$(DEST_PLIST): $(SRC_YAML) $(SYNTAXDEV)
	$(SYNTAXDEV) build-plist --in "$<" --out "$@"

devenv $(SYNTAXDEV):
	npm install syntaxdev@0.0.10
