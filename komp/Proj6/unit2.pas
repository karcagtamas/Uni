unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm2 }

  TForm2 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public
    constructor Create(AOwner: TComponent; Title, StarterText: String; MaxLength: Integer);

  end;

var
  Form2: TForm2;

implementation

{$R *.lfm}

constructor TForm2.Create(AOwner: TComponent; Title, StarterText: String; MaxLength: Integer);
begin
  inherited Create(AOwner);
  Label1.Caption := Title;
  Edit1.Text := StarterText;
  Edit1.MaxLength := MaxLength;
end;

{ TForm2 }

procedure TForm2.FormCreate(Sender: TObject);
begin

end;

procedure TForm2.Button1Click(Sender: TObject);
begin
   ModalResult:=mrOk;
end;

procedure TForm2.Button2Click(Sender: TObject);
begin
    ModalResult:=mrCancel;
end;

end.

