unit Proj1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    ConvertButton: TButton;
    ErrorButton: TButton;
    Circle: TButton;
    Solver: TButton;
    Divider: TButton;
    procedure ConvertButtonClick(Sender: TObject);
    procedure ErrorButtonClick(Sender: TObject);
    procedure CircleClick(Sender: TObject);
    procedure SolverClick(Sender: TObject);
    procedure DividerClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.SolverClick(Sender: TObject);
var
  a, b, c, x1, x2, d: Double;
  err: Integer;
begin
  Val(InputBox('A', 'A: ', ''), a, err);
  if err = 0 then
  begin
      Val(InputBox('B', 'B: ', ''), b, err);
      if err = 0 then
      begin
          Val(InputBox('C', 'C: ', ''), c, err);
          d := (b * b) - (4 * a * c);
          if d > 0 then
          begin
              x1 := (-b + Sqrt(d)) / (2 * a);
              x2 := (-b - Sqrt(d)) / (2 * a);
              ShowMessage('X1: ' + floattostr(x1) + ' X2: ' + FloatToStr(x2));
          end
          else if d = 0 then
          begin
               x1 :=  -b / (2 * a);
               ShowMessage('X1: ' + floattostr(x1));
          end else
          begin
                 ShowMessage('Noppe');
          end;


      end;
  end;
end;

procedure TForm1.DividerClick(Sender: TObject);
var n, err, res: Integer;
  i: Integer;
begin
    res := 0;
    Val(InputBox('N', 'N: ', ''), n, err);
    while (i < Sqrt(n)) and (res = 0) do
    begin
          if n mod i = 0 then
          begin
            res := i;
          end
          else
          begin
              i := i + 1;
          end;
    end;
    ShowMessage('Res: ' + res.ToString());

end;

procedure TForm1.CircleClick(Sender: TObject);
var
 t, k, r: Double;
 err: Integer;
begin
  Val(InputBox('Circle r', 'R: ', ''), r, err);
  if err = 0 then
  begin
    t := Pi()* Pi() * r;
    k := Pi() * 2 * r;

    ShowMessage('T: ' + floattostr(t) + ' K: ' + FloatToStr(k));
  end;
end;

procedure TForm1.ConvertButtonClick(Sender: TObject);
var
  i,j: Integer;
  s: String;
begin
 // Input box
  s := InputBox('Input', 'Here: ', '');

  // Condition
  if s.Length > 0 then   // Condition
  begin
    ShowMessage(s);
  end
  else
  begin
    ShowMessage('Not valid - is empty');
  end;

  // Convert string to integer
  Val(s, i, j);

  // Condition
  if j = 0 then
  begin
    s := '';
    // For
    for I := 1 to i do
    begin
      s := s + ' ' + I.ToString();
    end;
    ShowMessage(s);
  end
  else
  ShowMessage('Invalid converting');

  while False do begin end; // While - while is true
  repeat until (True); // Do while - while is false


end;

procedure TForm1.ErrorButtonClick(Sender: TObject);
var
  b: byte;
begin
  b := 255; // Over throught
  b := b + 2;
  ShowMessage(b.ToString());

end;

end.
