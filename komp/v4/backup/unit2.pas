unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, Math;

type

  { TForm2 }

  TForm2 = class(TForm)
    Image1: TImage;
    constructor Create(Sender: TComponent;x: Integer; y: Integer; r: Integer;count: Integer; starter: Integer; myColor: TColor);
    procedure Display();
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
  private

  public

  end;

var
  Form2: TForm2;
  XCord: Integer;
  YCord: Integer;
  RVal: Integer;
  CountVal: Integer;
  StarterVal: Double;
  MyColorVal: TColor;
  StepVal: Integer;

implementation

{$R *.lfm}

{ TForm2 }

constructor TForm2.Create(Sender: TComponent;x: Integer; y: Integer; r: Integer;count: Integer; starter: Integer; myColor: TColor);
begin
   inherited Create(Sender);
   XCord := x;
   YCord := y;
   RVal := r;
   CountVal := count;
   StarterVal := starter;
   MyColorVal := myColor;
   if (Count >= 3) or (Count <= 8) then
   begin
       StepVal := 10;
       ShowMessage('yee');
       Display();
       Image1.Canvas.Brush.Color:= TColor($ffffff);

   end
   else
   begin
        ShowMessage('Not valid constructor value');
        ShowMessage(Count.ToString());
        Form2.Close();
   end;
end;

procedure TForm2.Display();
var
  x: Integer;
  y: Integer;
  i: Integer;
  diff: Double;
begin
   Image1.Canvas.Clear();
   for i:= 0 to 100 do Image1.Canvas.Pixels[i,i] := TColor($ff3311);
   diff := 360 / CountVal;
   for i := 0 to CountVal do
    begin
      x := 0;
      y := 0;

      x := XCord + Floor(RVal * cos((StarterVal + (i * diff)) * 2 * PI / 360));
      y := YCord - Floor(RVal * sin((StarterVal + (i * diff)) * 2 * PI / 360));
      Image1.Canvas.Pixels[x, y] := MyColorVal;
    end;
end;

procedure TForm2.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState
  );
begin
    if Key.ToExtended() = 40 then
    begin
        YCord := YCord + StepVal;
    end;
    if Key.ToExtended() = 38 then
    begin
        YCord := YCord - StepVal;
    end;
    if Key.ToExtended() = 37 then
    begin
        XCord := XCord - StepVal;
    end;
    if Key.ToExtended() = 39 then
    begin
        XCord := XCord + StepVal;
    end;
    if Key.ToExtended() = 33 then
    begin
        RVal := RVal + StepVal;
    end;
    if Key.ToExtended() = 34 then
    begin
        if StepVal < RVal
        RVal := RVal - StepVal;
    end;
    if Key.ToExtended() = 36 then
    begin
        StarterVal := StarterVal + StepVal;
    end;
    if Key.ToExtended() = 35 then
    begin
       StarterVal := StarterVal - StepVal;
    end;
    if Key.ToExtended() = 45 then
    begin
         if CountVal < 8 then CountVal := CountVal + 1;
    end;
    if Key.ToExtended() = 46 then
    begin
        if CountVal > 3 then CountVal := CountVal - 1;
    end;
    Display();
end;



end.
                                         /
