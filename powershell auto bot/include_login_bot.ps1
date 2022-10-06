function login ([string]$email, [string]$pass) {
    $Email = $email
    $Password = $pass


Add-Type -Path ".\WebDriver.dll"


$edge_object = New-Object "OpenQA.Selenium.Edge.EdgeDriver"
$edge_object.Navigate().GoToURL( "https://webmail.healthbc.org/my.policy" )

$InputUser = $edge_object.FindElement([OpenQA.Selenium.By]::Id("input_1"))
$InputUser.SendKeys($Email)
$PasswordUser = $edge_object.FindElement([OpenQA.Selenium.By]::Id("input_2"))
$PasswordUser.SendKeys($Password)
$LoginButton = $edge_object.FindElement([OpenQA.Selenium.By]::Id("submit_row"))
$LoginButton.Click()
    
}

