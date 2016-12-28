DIR = insertion bubble

all: $(addsuffix _sort, $(DIR))

%_sort: 
	$(MAKE) -C $(patsubst %_sort, %/, $@)

clean: $(DIR)
	for d in $(DIR); do\
		$(MAKE) clear -C $$d;\
	done
