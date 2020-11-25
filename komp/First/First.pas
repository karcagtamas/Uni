unit First;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ComCtrls, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Button1: TButton;
    Alma: TScrollBar;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    OpenDialog1: TOpenDialog;
    ColorPicker: TColorBox;
    GridPanel1: TGridPanel;
    ColorDialog1: TColorDialog;
    FontDialog1: TFontDialog;
    Timer: TTimer;
    procedure NemAlma(Sender: TObject);
    procedure Button3MouseEnter(Sender: TObject);
    procedure Button3MouseLeave(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure ColorChange(Sender: TObject);
    procedure TimerTimer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button2Click(Sender: TObject);
begin
    Label1.Visible := not Label1.Visible;
    Alma.Position := Alma.Position + 10000;
    OpenDialog1.Execute();
end;

procedure TForm1.Button3MouseEnter(Sender: TObject);
begin
      Button2.Visible := False;
      Button3.Top := Random(300);
      Button3.Left := Random(300);
end;

procedure TForm1.Button3MouseLeave(Sender: TObject);
begin
      Button2.Visible := True;
      Button2.Top := Random(100);
      Button2.Left := Random(100);
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
      Label1.Top := Random(500);
      Label1.Left := Random(500);
      ColorDialog1.Execute();
      Label1.Font.Color := ColorDialog1.Color;
      FontDialog1.Execute();
      Label1.Font := FontDialog1.Font;
end;

procedure TForm1.ColorChange(Sender: TObject);
begin
  Label1.Font.Color := ColorPicker.Selected;
end;

procedure TForm1.NemAlma(Sender: TObject);
begin

  if not Button2.Visible and Label1.Enabled then showMessage('Alma');
  Label1.Enabled := False;
  Label1.Caption := 'Most már nem változtathatod meg. Hihi :D';
end;

procedure TForm1.TimerTimer(Sender: TObject);
begin
  Label1.Font.Size := Label1.Font.Size + 1;
  Form1.Color := Random(9999);
end;

end.

// dpr - delphi project
// dproj - proj settings
// res - resources
// dfm - form design
// exe -
