unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    ListBox1: TListBox;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;
  i: Integer;
  form: TForm2;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin
  TListBox(ListBox1).Items.Add('Alma' + i.ToString());
  i := i + 1;
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  selected: String;
begin
     selected := ListBox1.GetSelectedText();
     ShowMessage(selected);
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
    form := TForm2.Create(self);
    form.ShowModal();
end;



end.

