using System;
using System.Text;

public static class CognitoTokenUtils
{
    public static string GetCognitoUsername(string idToken)
    {
        return GetStringClaim(idToken, "cognito:username");
    }

    public static string GetStringClaim(string jwt, string claimName)
    {
        if (string.IsNullOrEmpty(jwt) || string.IsNullOrEmpty(claimName)) return "";

        string[] parts = jwt.Split('.');
        if (parts.Length < 2) return "";

        string payloadJson;
        try
        {
            payloadJson = DecodeBase64Url(parts[1]);
        }
        catch (Exception)
        {
            return "";
        }

        string claimToken = "\"" + claimName + "\"";
        int claimIndex = payloadJson.IndexOf(claimToken, StringComparison.Ordinal);
        if (claimIndex < 0) return "";

        int colonIndex = payloadJson.IndexOf(':', claimIndex + claimToken.Length);
        if (colonIndex < 0) return "";

        int valueStart = colonIndex + 1;
        while (valueStart < payloadJson.Length && char.IsWhiteSpace(payloadJson[valueStart])) valueStart++;
        if (valueStart >= payloadJson.Length || payloadJson[valueStart] != '"') return "";

        valueStart++;
        StringBuilder value = new StringBuilder();
        bool escaped = false;

        for (int i = valueStart; i < payloadJson.Length; i++)
        {
            char c = payloadJson[i];
            if (escaped)
            {
                value.Append(c);
                escaped = false;
                continue;
            }

            if (c == '\\')
            {
                escaped = true;
                continue;
            }

            if (c == '"') return value.ToString();
            value.Append(c);
        }

        return "";
    }

    private static string DecodeBase64Url(string base64Url)
    {
        string base64 = base64Url.Replace('-', '+').Replace('_', '/');
        switch (base64.Length % 4)
        {
            case 2:
                base64 += "==";
                break;
            case 3:
                base64 += "=";
                break;
        }

        byte[] bytes = Convert.FromBase64String(base64);
        return Encoding.UTF8.GetString(bytes);
    }
}
