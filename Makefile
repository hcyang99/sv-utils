STD_CELLS = 
HEADER = include/sv_vector.svh
TESTBENCH = testbench/sv_vector_test.sv
VERILOG =   
UTILS = utils/sv_vector.cpp

VV         = vcs -full64 -cpp g++ -cc gcc -LDFLAGS -Wl,--no-as-needed +lint=TFIPC-L -notice
VVOPTS     = -o $@ +v2k +vc +warn=all -sverilog -timescale=1ns/1ps 

ifdef WAVES
VVOPTS += +define+DUMP_VCD=1 +memcbk +vcs+dumparrays +sdfverbose
endif

ifdef GUI
VVOPTS += -gui
endif

ifdef DEBUG
VVOPTS += -debug_access+all
endif

ifdef COVERAGE
VVOPTS += -cm line+cond+tgl
endif

all: clean

.PHONY: sim gb_sim clean mult_sim down_sim

clean:
	# rm -rf temp/*
	rm -rf alib-52/
	rm -rf *.log
	rm -rf *.svf
	rm -rf ucli.key
	rm -rf *.daidir
	rm -rf *.vdbs
	rm -rf csrc/
	rm -rf urgReport/
	rm -rf DVEfiles/
	rm -rf *sim
	rm -rf *.vpd
	rm -rf *.old
	rm -rf *.txt

sim: $(HEADER) $(TESTBENCH) $(VERILOG)
	$(VV) $(VVOPTS) $(TESTBENCH) $(VERILOG) $(UTILS); ./$@