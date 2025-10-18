.PHONY: clean All

All:
	@echo "==========Building project:[ 18Graphs - Debug ]=========="
	@cd "18Graphs" && "$(MAKE)" -f  "18Graphs.mk"
clean:
	@echo "==========Cleaning project:[ 18Graphs - Debug ]----------"
	@cd "18Graphs" && "$(MAKE)" -f  "18Graphs.mk" clean
