`ifndef __SV_VECTOR_SVH
`define __SV_VECTOR_SVH

import "DPI-C" function chandle svv_new();
import "DPI-C" function chandle svv_new_winfo(string s);
import "DPI-C" function chandle svv_copy(chandle other);
import "DPI-C" function chandle svv_copy_winfo(chandle other, string s);
import "DPI-C" function void svv_delete(chandle v);
import "DPI-C" function int svv_at(chandle v, int loc);
import "DPI-C" function void svv_set(chandle v, int loc, int value);
import "DPI-C" function void svv_push_back(chandle v, int value);
import "DPI-C" function int svv_pop_back(chandle v);
import "DPI-C" function void svv_push_front(chandle v, int value);
import "DPI-C" function int svv_pop_front(chandle v);
import "DPI-C" function int svv_size(chandle v);
import "DPI-C" function void svv_shuffle(chandle v);

`endif
