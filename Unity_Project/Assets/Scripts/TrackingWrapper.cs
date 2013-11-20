using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.IO;
using UnityEngine;
using Microsoft;

public class TrackingWrapper
{
    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trInitialize")]
    public static extern void Initialize();

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trShutdown")]
    public static extern void Shutdown();

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trGetNumPlayers")]
    public static extern uint GetNumPlayers(uint sensor);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trSetNumPlayers")]
    public static extern void SetNumPlayers(uint sensor, uint amount);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trGetNumSensors")]
    public static extern uint GetNumSensors();

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trUpdate")]
    public static extern void Update(uint sensor);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trGetPlayerPositionX")]
    public static extern float GetPlayerPoitionX(uint sensor, uint player);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trGetPlayerPositionZ")]
    public static extern float GetPlayerPoitionZ(uint sensor, uint player);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trIsPlayerThrowing")]
    public static extern bool IsPlayerThrowing(uint sensor, uint player);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trShowDebugger")]
    public static extern void ShowDebugger(uint sensor, bool visible);

    [DllImportAttribute(@"Tracking.dll", EntryPoint = "trIsDebuggerVisible")]
    public static extern bool IsDebuggerVisible(uint sensor);
}
