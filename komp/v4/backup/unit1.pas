unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  Form: TForm2;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
var rand: Integer;
begin
  rand := random(6) + 3;
  Form := TForm2.Create(self, 150, 150, 100, rand, 360, TColor($11FF33));
  if Form.ShowModal = mrOk then
  begin

  end;


end;

end.

