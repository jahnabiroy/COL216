module dddd(
    input clk,
    input rst,
    input signed [15:0] a, // m
    input signed [15:0] b, // q
    output reg signed [31:0]c_cs1221094=32'b0,
    output reg [0:0] completed = 0,
    input loaded,
    output reg[31:0] clock_cycle_cs1221596
);
    reg signed[31:0]result = 32'b0;
    reg[4:0]i=0;
    reg[4:0]j=0;
    reg[5:0]index=0;
    reg q=0;
    reg [31:0] cl_cycle = 0;
    always @(posedge clk or posedge rst)begin
        //$display("%d,%d,%d,%d\n",i,j,index,result);
        if (rst) begin
            completed <= 0;
            i <= 0;
            j <= 0;
            q <= 0;
            result <= 0;
            index <= 0;
            clock_cycle_cs1221596 <= 0;
            cl_cycle <= 0;
        end
        else if(index<16 & loaded == 1)begin
            cl_cycle <= cl_cycle + 1;
            if((j)<16 & a[j]==q)begin///0
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///1
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///2
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///3
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///4
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///5
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///6
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///7
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///8
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///9
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///10
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///11
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///12
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///13
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///14
                j=j+1;
            end
            if((j)<16 & a[j]==q)begin///15
                j=j+1;
            end
            if(q==1)begin
                result=result+(b<<(j));
                result=result-(b<<(i));
            end
            i=j;
            index=i;
            q=a[j];
        end
        if(index==16)begin
            c_cs1221094<=result[31:0];
            completed<=1;
            clock_cycle_cs1221596 <= cl_cycle;
            $display("clock cycles: %0d", cl_cycle);
            index<=0;
        end
    end
endmodule

module tb_variableLatencyMultiplier();
    reg signed [15:0] a;
    reg signed [15:0] b;
    wire signed [31:0] c_cs1221094;
    integer signed expected_result=0;
    reg clk =1;
    reg rst = 0;
    localparam CLK_PERIOD=10;
    always#(CLK_PERIOD/2)clk=~clk;
    wire completed;
    reg loaded=0;
    wire [31:0] clock_cycle_cs1221596;
    integer test_counter=0;
    integer i = 0;
    
    dddd uut(
        .clk(clk),
        .rst(rst),
        .a(a),
        .b(b),
        .c_cs1221094(c_cs1221094),
        .completed(completed),
        .loaded(loaded),
        .clock_cycle_cs1221596(clock_cycle_cs1221596)

    );
    
    initial begin
        // Synchronize with the initial state
//        @(posedge clk);

        while (test_counter < 500) begin
            // Generate new test case
            $display("Generating Testcase %0d:", test_counter+1);
            a = $urandom_range(1 << 16);
            a = a[15] ? -a: a;
            b = $urandom_range(1 << 16);
            
            loaded = 1;
            test_counter = test_counter + 1;
            
            rst = 1;
            #5;  // Hold reset for a few cycles
            rst = 0;
            
            
            // Wait for completion
//            @(posedge clk);
            while (!uut.completed) @(posedge clk);
            expected_result=a*b;
            // Check results
            if (expected_result==c_cs1221094) begin
                $display("%d",clock_cycle_cs1221596);
                $display("a=%0d, b=%0d, c_cs1221094=%0d, expected=%0d, Passed", a, b, c_cs1221094, expected_result);
            end
            else begin
                $display("Failed");
            end
            
            
            // Reset loaded for the next test case
            loaded = 0;
            
        end

        $finish;
    end

    
    
//    always@(posedge clk)begin
//        if(completed==1)begin
//            expected_result=a*b;
////            $display("%d,%d,%d,%d\n",a,b,c,expected_result);
//            if(expected_result==c)begin
//                $display("Test passed\n");
//            end
//            else begin
//                $display("Test failed\n");
//            end
//            loaded=0;
//            //$finish;
//        end
//        if(i>=0)begin
//            $display("In %d\n",i);
//            a=16'b1010101010101010;
//            a = a[15] ? -a: a;
//            b=1;
////            a = 1234;
////            b = -2578;
//            $display("%b,%b\n",a,b);
//            i=i+1;
//            #1;
//            loaded=1;
//        end
//    end

endmodule
`default_nettype wire