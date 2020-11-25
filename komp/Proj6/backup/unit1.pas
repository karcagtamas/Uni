unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Label1: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);

  private

  public
       function StringIsEmpty(val: String): Boolean;
  end;

var
  Form1: TForm1;
  InputForm: TForm;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
begin

end;

procedure TForm1.Button1Click(Sender: TObject);
var
  form: TForm2;
  result: String;
begin
     form := TForm2.Create(self, 'Please: ', '', 20);
     if form.ShowModal = mrOk then
     begin
          ShowMessage(form.Edit1.Text);
          result := form.Edit1.Text;
          if StringIsEmpty(val) then
           begin
                ShowMessage('Value cannot be empty');
           end;
     end;

end;

function TForm1.StringIsEmpty(val: String): Boolean;
var
  res: Boolean;
begin
     res := False;
    if val = '' then
     begin
          res := True;
     end;
    Result := res;
end;

end.

