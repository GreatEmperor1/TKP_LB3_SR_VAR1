Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        Dim obj As Object
        obj = CreateObject("Server.CoFun.1")
        z11.Text = obj.Fun11(x11.Text, y11.Text)
        obj = Nothing

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        Dim obj As Object
        obj = CreateObject("Server.CoFun.1")
        d12.Text = obj.Fun12(a12.Text, b12.Text, c12.Text)
        obj = Nothing

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click

        Dim obj As Object
        obj = CreateObject("Server.CoFun.1")
        out13.Text = obj.Fun13(in13.Text)
        obj = Nothing

    End Sub


End Class
