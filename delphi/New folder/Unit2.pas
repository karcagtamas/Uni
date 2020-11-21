unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ToolWin, Vcl.ComCtrls, Vcl.ImgList,
  Vcl.ExtCtrls, Vcl.StdCtrls;

type
  TForm2 = class(TForm)
    ToolBar1: TToolBar;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton4: TToolButton;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    ToolButton10: TToolButton;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    ToolButton13: TToolButton;
    ToolButton14: TToolButton;
    ToolButton15: TToolButton;
    ToolButton16: TToolButton;
    ControlBar1: TControlBar;
    Label1: TLabel;
    ToolBar2: TToolBar;
    Label2: TLabel;
    ToolButton17: TToolButton;
    ToolButton18: TToolButton;
    ToolButton19: TToolButton;
    ToolButton20: TToolButton;
    ToolButton21: TToolButton;
    ToolButton22: TToolButton;
    ToolBar3: TToolBar;
    Label3: TLabel;
    ImageList2: TImageList;
    ImageList1: TImageList;
    ToolButton23: TToolButton;
    procedure KerekChange(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}

procedure TForm2.KerekChange(Sender: TObject);
var btn: TToolButton;
begin
  btn := Sender as TToolButton;
  btn.ImageIndex := btn.ImageIndex + 1;
  if btn.ImageIndex >= 16 then
  begin
    btn.ImageIndex := 0;
  end;
end;

end.
