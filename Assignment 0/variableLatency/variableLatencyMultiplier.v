`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.01.2024 19:24:39
// Design Name: 
// Module Name: variable
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module variable(
    input clk,
    input signed [15:0] a, // m
    input signed [15:0] b, // q
    output reg signed [31:0]c_cs1221596 =32'b0,
    output reg [0:0] completed = 0,
    input loaded
);
    reg signed[31:0]result = 32'b0;
    reg[4:0]i=0;
    reg[4:0]j=0;
    reg[5:0]index=0;
    reg q=0;
    always @(posedge clk)begin
        //$display("%d,%d,%d,%d\n",i,j,index,result);
        if(index<16 & loaded == 1)begin
            if((j)<16 & a[j]==q)begin///0
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///1
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///2
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///3
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///4
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///5
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///6
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///7
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///8
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///9
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///10
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///11
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///12
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///13
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///14
                j<=j+1;
            end
            if((j)<16 & a[j]==q)begin///15
                j<=j+1;
            end
            if(q==1)begin
                result=result+(b<<(j));
                result=result-(b<<(i));
            end
            //$display("%d,%d,%d,%d\n",i,j,index,result);
            i=j;
            index=i;
            q<=a[j];
        end
        if(index>=16)begin
            c_cs1221596<=result[31:0];
            completed<=1;
        end
    end
endmodule
