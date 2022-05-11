`include "include/sv_vector.svh"

//  Module: sv_vector_test
//
module sv_vector_test;

    task run_tests;
        chandle vec = svv_new_winfo("vec");
        chandle new_vec;

        svv_push_back(vec, 1);
        svv_push_back(vec, 4);
        svv_push_back(vec, 9);
        svv_push_back(vec, 16);
        svv_push_back(vec, 25);

        new_vec = svv_copy_winfo(vec, "new_vec");
        svv_shuffle(new_vec);
        
        for (int i = 0; i < svv_size(vec); ++i) begin
            $display("vec[%2d] = %4d", i, svv_at(vec, i));
        end
    endtask

    initial begin
        run_tests();
        $finish;
    end
    
endmodule: sv_vector_test
