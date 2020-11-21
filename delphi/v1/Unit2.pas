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
    ImageList1: TImageList;
    ImageList2: TImageList;
    ToolButton23: TToolButton;
    Timer1: TTimer;
    Button1: TButton;
    Button2: TButton;
    ComboBox1: TComboBox;
    Label4: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    ComboBox2: TComboBox;
    Edit1: TEdit;
    ToolBar4: TToolBar;
    Label5: TLabel;
    ToolBar5: TToolBar;
    ToolBar6: TToolBar;
    Label8: TLabel;
    Label9: TLabel;
    ToolButton24: TToolButton;
    ToolButton25: TToolButton;
    ToolButton26: TToolButton;
    procedure KerekChange(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure ComboBox1Change(Sender: TObject);
    procedure MultiChange(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  currentKerekIndex: Integer;
  onForgas: boolean;
  money: Integer;
  x2MultiId: Integer;
  x5MultiId: Integer;
  x10MultiId: Integer;

implementation

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
begin
  onForgas := true;
  button1.Enabled := false;
  button2.Enabled := true;
end;

procedure TForm2.Button2Click(Sender: TObject);
var
I: Integer;
tet: Integer;
err: Integer;
multi: Integer;
begin
  multi := 0;
  onForgas := false;
  button2.Enabled := false;
  button1.Enabled := true;
  tet := ComboBox2.ItemIndex + 1;

  if ToolBar3.Buttons[0].ImageIndex = ToolBar4.Buttons[0].ImageIndex then
  begin
    multi := 2;
  end;

  if ToolBar3.Buttons[0].ImageIndex = ToolBar5.Buttons[0].ImageIndex then
  begin
    multi := 5;
  end;

  if ToolBar3.Buttons[0].ImageIndex = ToolBar6.Buttons[0].ImageIndex then
  begin
    multi := 10;
  end;
  money := money - tet;
  money := money + tet * multi;
  Edit1.Text := inttostr(money);


  ComboBox2.Clear();
  for I := 1 to money do
  begin
       ComboBox2.AddItem(inttostr(I), nil);
  end;
  if money >= tet then
  begin
    ComboBox2.ItemIndex := tet - 1;
  end
  else
  begin
    ComboBox2.ItemIndex := 0;
  end;

  if money = 0 then button1.Enabled := false;
end;

procedure TForm2.ComboBox1Change(Sender: TObject);
var value, err: Integer;
begin
    val(ComboBox1.Items[ComboBox1.ItemIndex], value, err);
    if err = 0 then
    begin
        Timer1.Interval := value;
    end;
end;

procedure TForm2.FormCreate(Sender: TObject);
var i: Integer;
begin
  currentKerekIndex := 0;
  onForgas := false;
  for i := 1 to 100 do
  begin
      Combobox2.AddItem(inttoStr(i), nil);
  end;
  ComboBox2.ItemIndex := 0;
  for I := 1 to 10 do
  begin
    Combobox1.AddItem(inttostr(i * 100), nil);
  end;
  ComboBox1.ItemIndex := 0;

  money := 100;
  Edit1.Text := inttostr(money);
  Edit1.Enabled := false;

  button2.Enabled := false;

  x2MultiId := 0;
  x5MultiId := 0;
  x10MultiId := 0;
  ToolBar4.Buttons[0].ImageIndex := ToolBar2.Buttons[x2MultiId].ImageIndex;
  ToolBar5.Buttons[0].ImageIndex := ToolBar2.Buttons[x5MultiId].ImageIndex;
  ToolBar6.Buttons[0].ImageIndex := ToolBar2.Buttons[x10MultiId].ImageIndex;
end;

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

procedure TForm2.MultiChange(Sender: TObject);
var btn: TToolButton;
begin
    btn := Sender as TToolButton;
    if btn.Tag = 2 then
    begin
       x2MultiId := x2MultiId + 1;
       if x2MultiId >= 6 then
       begin
         x2MultiId := 0;
       end;
        btn.ImageIndex := ToolBar2.Buttons[x2MultiId].ImageIndex;
    end;
    if btn.Tag = 5 then
    begin
       x5MultiId := x5MultiId + 1;
       if x5MultiId >= 6 then
       begin
         x5MultiId := 0;
       end;
        btn.ImageIndex := ToolBar2.Buttons[x5MultiId].ImageIndex;
    end;
    if btn.Tag = 10 then
    begin
       x10MultiId := x10MultiId + 1;
       if x10MultiId >= 6 then
       begin
         x10MultiId := 0;
       end;
        btn.ImageIndex := ToolBar2.Buttons[x10MultiId].ImageIndex;
    end;
end;

procedure TForm2.Timer1Timer(Sender: TObject);
var
imageIndex: Integer;
begin
  if onForgas then
  begin
      currentKerekIndex := currentKerekIndex +1;
      if currentKerekIndex >= 6 then
      currentKerekIndex := 0;
      imageIndex := ToolBar2.Buttons[currentKerekIndex].ImageIndex;
      Toolbar3.Buttons[0].ImageIndex := imageIndex;
  end;
end;

end.
