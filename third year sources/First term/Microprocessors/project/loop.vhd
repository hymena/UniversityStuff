entity waitfor is 
end entity;
-- comment line 
architecture sim of waitfor is 
begin

    process is 
    begin
        
        report "Selam canım ben amcanım";
        wait for 10 ns;
        
    end process;


end architecture;