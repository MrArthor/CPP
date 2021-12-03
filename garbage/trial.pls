declare
        

begin
    function isStrong(n:integer):boolean;
    var
        i,j,k,sum:integer;
    begin
        sum:=0;
        for i:=1 to n do
        begin
        for j:=1 to n do
        begin
            k:=i*j;
            sum:=sum+k;
        end;
        end;
        if sum=n then
        begin
            isStrong:=true;
        end
        else
        begin
            isStrong:=false;
        end;
    end;
    var
        n:integer;
    begin
        write('Enter the number: ');
        readln(n);
        for i:=1 to n do
        begin
            if isStrong(i) then
            begin
                writeln(i);
            end;
        end;
    end;
end.