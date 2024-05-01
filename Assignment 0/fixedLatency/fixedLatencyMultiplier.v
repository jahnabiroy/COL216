module fixedLatencyMultiplier(
    input clk,
    input [15:0] a,
    input [15:0] b,
    input rst,  // Added reset input
    output reg [31:0] c_cs1221094= 32'b0,
    output reg completed = 0
);
    reg [31:0] result = 32'b0;
    reg [4:0] i = 5'b0;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            result <= 32'b0;
            i <= 5'b0;
            completed <= 0;
        end else begin
            if (i < 16) begin
                if (a[i] == 1) begin
                    result <= result + (b << i);
                end
                i <= i + 1;
            end
            if (i == 16) begin
                c_cs1221094<= result;
                completed <= 1;
                i <= i + 1;
            end
        end
    end
endmodule

//module tb_fixedLatencyMultiplier();
//    reg [15:0] a;
//    reg [15:0] b;
//    wire [31:0] c_cs1221094;
//    reg clk = 0;
//    reg rst = 1; // Initial reset value
//    reg [2:0] i = 1;
//    integer expected_result;
//    localparam CLK_PERIOD = 10;

//    always #(CLK_PERIOD/2) clk =~clk;

//    fixedLatencyMultiplier uut(
//        .clk(clk),
//        .a(a),
//        .b(b),
//        .rst(rst),  // Pass reset signal
//        .c_cs1221094(c_cs1221094),
//        .completed()

//    );

//    always @(posedge clk) begin
//        if (uut.completed == 1) begin
//            expected_result = a * b;
//            if (expected_result == c_cs1221094) begin
//                $display("Test passed\n");
//            end else begin
//                $display("Test failed\n");
//            end
//            rst <= 1; // Reset after each test
//            a = $random % (1 << 16);
//            b = $random % (1 << 16);
//            i = i + 1;
//        end
//    end

//endmodule

`default_nettype wire
