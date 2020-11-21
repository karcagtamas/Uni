unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Alakzatok, NagyHal, Vcl.ExtCtrls;

type
  TForm2 = class(TForm)
    Image1: TImage;
    Timer1: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure GenerateKisHalak();
    procedure Timer1Timer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  NagyH: TNagyHal;
  KisHalak: array[0..9] of TTeliKor;
  LastDirection: Extended;

implementation

{$R *.dfm}

procedure TForm2.FormCreate(Sender: TObject);
var
centerX, centerY: Integer;
begin
    Image1.Left := 0;
    Image1.Top := 0;
    Image1.Width := Form2.ClientWidth;
    Image1.Height := Form2.ClientHeight;
    centerY := Form2.ClientHeight div 2;
    centerX := Form2.ClientWidth div 2;
    NagyH := TNagyHal.Create(centerX, centerY, 30, TColor($FF0000), 10);
    NagyH.Kirak(TColor($FF0000), Image1.Canvas);
    GenerateKisHalak();
end;

procedure TForm2.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
    LastDirection := Key.ToExtended();
end;

procedure TForm2.GenerateKisHalak;
var
I, posX, posY: Integer;
begin
  for I := 0 to 9 do
  begin
    posX := random(Image1.Width - 20) + 10;
    posY := random(Image1.Height - 20) + 10;
    KisHalak[I] := TTeliKor.Create(posX, posY, 10, TColor($00FF00));
    KisHalak[I].Kirak(KisHalak[I].Szin, Image1.Canvas);
  end;

end;

procedure TForm2.Timer1Timer(Sender: TObject);
var
  I: Integer;
begin
     if (LastDirection = 40) and ((NagyH.y + NagyH.Speed) <= (Image1.Height - 30)) then
    NagyH.Mozgat(0, NagyH.Speed, Image1.Canvas);
  if (LastDirection = 38)  and ((NagyH.y - NagyH.Speed) >= 30) then
    NagyH.Mozgat(0, -NagyH.Speed, Image1.Canvas);
  if (LastDirection = 37) and ((NagyH.x - NagyH.Speed) >= 30) then
    NagyH.Mozgat(-NagyH.Speed, 0, Image1.Canvas);
  if (LastDirection = 39) and ((NagyH.x + NagyH.Speed) <= (Image1.Width - 30)) then
    NagyH.Mozgat(NagyH.Speed, 0, Image1.Canvas);

  for I := 0 to 9 do
  begin
      if KisHalak[i] <> nil then
      begin
          if ((KisHalak[I].x + 10) < (NagyH.x + 30))
            and ((KisHalak[I].x - 10) > (NagyH.x - 30))
            and ((KisHalak[I].y + 10) < (NagyH.y + 30))
            and ((KisHalak[I].y - 10) > (NagyH.y - 30))
         then
         begin
             KisHalak[i].Destroy(Image1.Canvas);
             KisHalak[i] := nil;
         end;
      end;
  end;
end;

end.
