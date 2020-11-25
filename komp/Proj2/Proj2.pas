unit Proj2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TMyForm = class(TForm)
    StaticArray: TButton;
    DynamicArray: TButton;
    SetDemo: TButton;
    StudentGenerator: TButton;
    StringCount: TButton;
    Button1: TButton;
    procedure StaticArrayClick(Sender: TObject);
    procedure DynamicArrayClick(Sender: TObject);
    procedure SetDemoClick(Sender: TObject);
    procedure StudentGeneratorClick(Sender: TObject);
    procedure StringCountClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }

  end;



var
  MyForm: TMyForm;

implementation

{$R *.dfm}

procedure TMyForm.SetDemoClick(Sender: TObject);

var
h: set of Byte;
input: Byte;
err: Integer;
valid: Boolean;
begin
    h := [];
    valid := True;
    while True do
    begin
       Val(InputBox('Give a number', 'N', ''), input, err);
       if input in h then
       begin
          ShowMessage('Already exists. Bye!');
          valid := False;
       end
       else
       begin
          include(h, input);
       end;
    end;
     
end;

procedure TMyForm.StringCountClick(Sender: TObject);
const H = ['a'..'z'];
var
count: Integer;
val: string;
I: Integer;
begin
   count := 0;
   val := InputBox('Value: ', '', '');
   for I := 0 to length(val) do
   begin
     if val[I] in H then
     begin
       count := count + 1;
     end;
   end;
   ShowMessage('Count: ' + count.ToString());
end;

procedure TMyForm.Button1Click(Sender: TObject);
var
  startV, endV, count , err, I, curr: Integer;
  h: set of Byte;
  res: array of Integer;
  s: string;
begin
  Val(InputBox('Start value:', 'StartV', ''), startV, err);
  if err = 0 then
  begin
    Val(InputBox('End value:', 'EndV', ''), endV, err);
    if err = 0 then
    begin
       Val(InputBox('Count:', 'Count', ''), count, err);
       if err = 0 then
       begin
         SetLength(res, count);
         s := '';
         for I := 0 to count - 1 do
         begin
            repeat
              curr := random(endV - startV) + startV;
            until (not(curr in h));
            Include(h, curr);
            res[I] := curr;
            s := s + res[I].ToString() + ' ';
         end;
         ShowMessage(s);
       end;

    end;

  end;

end;

procedure TMyForm.DynamicArrayClick(Sender: TObject);
var
t: array of Integer;
n: Integer;
err: Integer;
I: Integer;
res: string;
begin
    Val(InputBox('Give a number', 'N', ''), n, err);
    if err = 0 then
    begin
      SetLength(t, n);
      I := 0;

      // Get array values
      repeat
          Val(InputBox('Give a number ' + I.ToString(), I.ToString(), ''), t[I], err);
          if err = 0 then
          begin
            I := I + 1;
          end;
      until I >=   n;

      // Generate response string
      for I := n - 1 downto 0 do
      begin
          if I = 0 then
          begin
            res := res + t[I].toString() + '(' + I.ToString + '.)';
          end
          else
          begin
            res := res + t[I].toString() + '(' + I.ToString + '.)' + ', ';
          end;
      end;

      // Return response
      ShowMessage(res);
    end;

end;

procedure TMyForm.StaticArrayClick(Sender: TObject);
var
t: array[1..10] of Integer;
n: Integer;
err: Integer;
  I: Integer;
  res: string;
begin
  // Get N number
  Val(InputBox('Give a number', 'N', ''), n, err);

  if (n > 10) or (n < 1) then
  begin
    ShowMessage('Invalid intervall. Must be greater than zero and less than eleven');
  end
  else if err <> 0 then
  begin
     ShowMessage('Invalid input');
  end
  else
  begin
    I := 1;

    // Get array values
    repeat
        Val(InputBox('Give a number ' + I.ToString(), I.ToString(), ''), t[I], err);
        if err = 0 then
        begin
          I := I + 1;
        end;
    until I > n;

    // Generate response string
    for I := n downto 1 do
    begin
        if I = 1 then
        begin
          res := res + t[I].toString() + '(' + I.ToString + '.)';
        end
        else
        begin
          res := res + t[I].toString() + '(' + I.ToString + '.)' + ', ';
        end;
    end;

    // Return response
    ShowMessage(res);
  end;
end;

procedure TMyForm.StudentGeneratorClick(Sender: TObject);
const FOR_NAME = 'qwertzuiopasdfghjklyxcvbnm';
const FOR_NC = 'QWERTZUIOPASDFGHJKLYXCVBNM123456789';
type
    TStudent = record
    Name: string[40];
    NC: string[6];
    Grade: 1..5;
end;
var
student: TStudent;
I: Integer;
begin
   // Refresh ranfom method on call
   randomize;
   // Generate Name
   student.Name := '';
   for I := 0 to 1 do
   begin
     student.Name := student.Name + FOR_NAME[random(length(FOR_NAME) - 1)];
   end;

   // Generate Neptun Code
   student.NC := '';
   for I := 0 to 5 do
   begin
     student.NC := student.NC + FOR_NC[random(length(FOR_NC) - 1)];
   end;
   student.Grade := random(5) + 1;
   ShowMessage(student.Name + ' ' + student.NC + ' ' + IntToStr(student.Grade));

   with student do begin
     // In this you can use only the field name without the 'student' record name
   end;
end;

end.
