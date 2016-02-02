all:  # the default Make task


SRC_YAML    := src/c-improved.syntax.yaml

DEST_PLIST  := C\ Improved.tmLanguage
DEST_SCOPES := misc/scopes

SYNTAXDEV   := node_modules/.bin/syntaxdev


.PHONY: all release check devenv

all: release

release .PHONY: $(DEST_PLIST) $(DEST_SCOPES)  # .PHONY: rebuild unconditionally

$(DEST_PLIST): $(SRC_YAML) $(SYNTAXDEV)
	$(SYNTAXDEV) build-plist --in "$<" --out "$@"

$(DEST_SCOPES): $(SRC_YAML) $(SYNTAXDEV)
	$(SYNTAXDEV) scopes --syntax "$<" > "$@"


do_check = \
	OUT=$$(mktemp) && trap "rm -r $$OUT" EXIT && \
		{ $2; } && git --no-pager diff --no-index $1 $$OUT

check: $(SRC_YAML) $(SYNTAXDEV)
	@$(call do_check, $(DEST_PLIST), \
		$(SYNTAXDEV) build-plist --in "$<" --out "$$OUT")
	@$(call do_check, $(DEST_SCOPES), \
		$(SYNTAXDEV) scopes --syntax "$<" > "$$OUT")


devenv $(SYNTAXDEV):
	npm install syntaxdev@0.0.10
