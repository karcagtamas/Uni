unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

  const NMax = 10;

type
  TForm1 = class(TForm)
    CallProcedure: TButton;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    procedure CallProcedureClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
    procedure Send(msg: String);
    function Double(x: Integer): Integer;
    procedure DoubleAction(src: Integer; var res: Integer);
    procedure WriteOut(const src: array of variant);
    procedure NameTest(input: String; var lengthOfName: Integer; var countOfSpaces: Integer; var countOfChars: Integer);
  public
    { Public declarations }
  end;

type TArray = array[0..NMax - 1] of Integer;
type TVArray = array of variant;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
result: Integer;
begin
  DoubleAction(12, result);
  ShowMessage(result.ToString());
end;

procedure TForm1.Button2Click(Sender: TObject);
var
t: TVArray;
I: Integer;
begin
    setLength(t, 10);
     for I := 1 to 10 do
      begin
        t[I - 1] := I;
      end;
     WriteOut(t);
end;

procedure TForm1.Button3Click(Sender: TObject);
var
countOfChars: Integer;
countOfSpaces: Integer;
lengthOfInput: Integer;
input: String;
begin
  input := InputBox('Hi', 'Text: ', '');
  NameTest(input, lengthOfInput, countOfSpaces, countOfChars);
  ShowMessage('Input: ' + input + ' Length of input: ' + lengthOfInput.ToString() + ' Count of spaces: ' + countOfSpaces.ToString() + ' Count of chars: ' + countOfChars.ToString());
end;

procedure TForm1.CallProcedureClick(Sender: TObject);
begin
  ShowMessage('Alma');
  Send('asdasdasd');
end;

procedure TForm1.Send(msg: String);
begin
  ShowMessage(msg + Double(3).ToString());
end;

function TForm1.Double(x: Integer): Integer;
begin
    Result := x * 2;
end;

procedure TForm1.DoubleAction(src: Integer; var res: Integer);
begin
     res := src * 2;
end;

procedure TForm1.WriteOut(const src: array of variant);
var
res: String;
I: Integer;
begin
   for I := 0 to length(src) - 1 do
   begin
     if I <> length(src) - 1 then
     begin
       res := res + VarToStr(src[I]) + ', ';
     end
     else
     begin
        res := res + VarToStr(src[I]);
     end;
   end;
   ShowMessage(res);
   ShowMessage(format('%d', [5*3]));
   ShowMessage(format('Kör sugara: %d, területe: %1.4f', [1, PI]));

end;

procedure TForm1.NameTest(input: String; var lengthOfName: Integer; var countOfSpaces: Integer; var countOfChars: Integer);
var
I: Integer;
begin
   lengthOfName := length(input);
   countOfSpaces := 0;
   countOfCHars := 0;
   for I := 1 to lengthOfName do
   begin
     if input[I] = ' ' then
     begin
       countOfSpaces := CountOfSpaces + 1;
     end
     else
     begin
       countOfChars := countOfChars + 1;
     end;

   end;
     
end;

end.
