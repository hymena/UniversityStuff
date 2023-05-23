library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
 
entity FSM_19290337 is
end entity;
 
architecture sim of FSM_19290337 is
 
    -- We are using a low clock frequency to speed up the simulation
    constant ClockFrequencyHz : integer := 100; -- 100 Hz
    constant ClockPeriod : time := 1000 ms / ClockFrequencyHz;
 
    signal Clk         : std_logic := '1';
    signal nRst        : std_logic := '0';
    signal NorthRed    : std_logic := '0';
    signal NorthYellow : std_logic := '0';
    signal NorthGreen  : std_logic := '0';
    signal WestRed     : std_logic := '0';
    signal WestYellow  : std_logic := '0';
    signal WestGreen   : std_logic := '0';
 
begin
 
    -- The Device Under Test (DUT)
    i_TrafficLights : entity work.TrafficLights_19290337(rtl)
    generic map(ClockFrequencyHz => ClockFrequencyHz)
    port map (
        Clk         => Clk,
        nRst        => nRst,
        NorthRed    => NorthRed,
        NorthYellow => NorthYellow,
        NorthGreen  => NorthGreen,
        WestRed     => WestRed,
        WestYellow  => WestYellow,
        WestGreen   => WestGreen);
 
    -- Process for generating clock
    Clk <= not Clk after ClockPeriod / 2;
 
    -- Testbench sequence
    process is
    begin
        wait until rising_edge(Clk);
        wait until rising_edge(Clk);
 
        -- Take the DUT out of reset
        nRst <= '1';
 
        wait;
    end process;
 
end architecture;