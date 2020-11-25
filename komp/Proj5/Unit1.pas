unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Pos: TLabel;
    Delete: TButton;
    procedure FormClick(Sender: TObject);
    procedure BtnClick(Sender: TObject);
    procedure DeleteClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.DeleteClick(Sender: TObject);
var
I: Integer;

begin
  for I := Form1.ComponentCount - 1 downto 0 do
  begin
  if (Form1.Components[I] is TButton) and ((Form1.Components[I] as TButton).Hint = 'A') then
  begin
        Form1.Components[I].Free();
  end;
  end;

end;

procedure TForm1.FormClick(Sender: TObject);
var
t: TPoint;
btn: TButton;
begin
  t := Mouse.CursorPos;
  t := ScreenToClient(t);
  // ShowMessage('X: ' + t.X.ToString() + ' Y: ' + t.Y.ToString());
  Pos.Caption := format('X: %d | Y: %d', [t.X, t.Y]);
  btn := TButton.Create(self);
  btn.Parent := self;
  btn.Left := t.X - 20;
  btn.Top := t.Y - 20;
  btn.Visible := True;
  btn.Height := 40;
  btn.Width := 40;
  btn.Caption := 'A';
  btn.Hint := 'A';

  btn.OnClick :=  BtnClick;
end;

procedure TForm1.BtnClick(Sender: TObject);
var
btn: TButton;
begin
  btn := Sender as TButton;
  (Sender as TButton).Font.Color := RGB(120, 120, 120);
  (Sender as TButton).Caption := 'B';
  btn.Height := btn.Height + 10;
  btn.Width := btn.Width + 10;
end;

end.
