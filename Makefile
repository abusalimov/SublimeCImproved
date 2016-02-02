all:  # the default Make task


SRC_YAML    := src/c-improved.syntax.yaml

DEST_PLIST  := C\ Improved.tmLanguage
DEST_SCOPES := misc/scopes

SYNTAXDEV   := node_modules/.bin/syntaxdev


.PHONY: all release devenv

all: release

release .PHONY: $(DEST_PLIST) $(DEST_SCOPES)  # .PHONY: rebuild unconditionally

$(DEST_PLIST): $(SRC_YAML) $(SYNTAXDEV)
	$(SYNTAXDEV) build-plist --in "$<" --out "$@"

$(DEST_SCOPES): $(SRC_YAML) $(SYNTAXDEV)
	$(SYNTAXDEV) scopes --syntax "$<" > "$@"

devenv $(SYNTAXDEV):
	npm install syntaxdev@0.0.10
