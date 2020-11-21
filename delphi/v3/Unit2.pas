unit Unit2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ToolWin, Vcl.ComCtrls, Vcl.StdCtrls,
  Vcl.ExtCtrls, Vcl.ImgList;

type
  TForm2 = class(TForm)
    ToolBar1: TToolBar;
    Button1: TButton;
    Button2: TButton;
    ImageList1: TImageList;
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
    Button3: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ToolButton1Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form2: TForm2;
  voltKeveres: boolean;
  imageCount: Integer;
  selectedImages: array[1..8] of Integer;
  emptyIndex: Integer;
  currentlyUp: array[0..1] of Integer;
  countOfCurrentlyUp: Integer;
  allUp: array[0..15] of Integer;
  countOfAllUp: Integer;
  gameOn: boolean;
  sugoOn: boolean;

implementation

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
var
selCount: Integer;
rnd: Integer;
was: boolean;
i: integer;

begin
    if voltKeveres <> true then
    begin
        selCount := 0;
       repeat
           rnd := random(imageCount) + 1;
           was := false;
           for i := 1 to selCount do
           begin
             if rnd = selectedImages[i] then
             begin
               was := true;
             end;
           end;
           if not was then
           begin
             selCount := selCount + 1;
             selectedImages[selCount] := rnd;
           end;
       until (selCount > 8);

       for i := 0 to ToolBar1.ButtonCount - 1 do
       begin
               ToolBar1.Buttons[i].ImageIndex := (i + 1) mod 8;
               ToolBar1.Buttons[i].Enabled := true;
       end;
       voltKeveres := true;
    end;
end;

procedure TForm2.Button2Click(Sender: TObject);
var
i: Integer;
temp: Integer;
begin
  if voltKeveres = true then
  begin
    for i := 0 to ToolBar1.ButtonCount - 1 do
    begin
    temp := ToolBar1.Buttons[i].ImageIndex;
        ToolBar1.Buttons[i].Hint := i.ToString + '-' + temp.ToString();
        ToolBar1.Buttons[i].ImageIndex := 100;
    end;
    countOfCurrentlyUp := 0;
    countOfAllUp := 0;
    Label1.Caption := 'Talált: ' + countOfAllUp.ToString();
    Label1.Visible := true;
    gameOn := true;
  end;
end;

procedure TForm2.Button3Click(Sender: TObject);
begin
  if gameOn = true then
  begin
    if sugoOn = true then
    begin
      sugoOn := false;
      Button3.Caption := 'Sugó';
    end
    else
    begin
       sugoOn := true;
       Button3.Caption := 'Vissza';
    end;
  end;
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
  voltKeveres := false;
  imageCount := 16;
  emptyIndex := 100;
  countOfCurrentlyUp := 0;
  countOfAllUp := 0;
  Label1.Visible := false;
  gameOn := false;
  sugoOn := false;
end;

procedure TForm2.ToolButton1Click(Sender: TObject);
var
imageIndex: Integer;
buttonIndex: Integer;
hint: String;
list: TStrings;
err: Integer;
button: TToolButton;
button1: TToolButton;
button2: TToolButton;
begin
  if sugoOn = false and gameOn = true then
  begin
    list := TStringList.Create();
    button := Sender as TToolButton;
    hint := button.Hint;
    ExtractStrings(['-'], [], PChar(hint), list);
    val(list[1], imageIndex, err);
    val(list[0], buttonIndex, err);
    button.ImageIndex := imageIndex;
    currentlyUp[countOfCurrentlyUp] := buttonIndex;
    countOfCurrentlyUp := countOfCurrentlyUp + 1;
    if countOfCurrentlyUp = 2 then
    begin
      button1 := Toolbar1.Buttons[currentlyUp[0]];
      button2 := Toolbar1.Buttons[currentlyUp[1]];
      if button1.ImageIndex = button2.ImageIndex then
      begin
          button1.Enabled := false;
          button2.Enabled := false;
          allUp[countOfAllUp] := currentlyUp[0];
          countOfAllUp := countOfAllUp + 1;
          allUp[countOfAllUp] := currentlyUp[1];
          countOfAllUp := countOfAllUp + 1;
      end
      else
      begin
          button1.ImageIndex := 100;
          button2.ImageIndex := 100;
      end;
      countOfCurrentlyUp := 0;
      Label1.Caption := 'Talált: ' + countOfAllUp.ToString();

    end;

    if countOfAllUp = 16 then
    begin
       gameOn := false;
       voltKeveres := false;
       countOfCurrentlyUp := 0;
        countOfAllUp := 0;
       ShowMessage('End of the game');
    end;


  end;

end;

end.
