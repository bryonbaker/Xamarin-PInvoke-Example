using System;
using System.Runtime.InteropServices;

namespace XamarinPInvokeTest
{
	public static class Wrapper
	{			
		[DllImport("__Internal", EntryPoint = "CreateTestClass")]
		public static extern IntPtr CreateTestClass();

		[DllImport("__Internal", EntryPoint = "GetNumber")]
		public static extern Int32 GetNumber( IntPtr pObject );

		[DllImport("__Internal", EntryPoint = "DisposeTestClass")]
		public static extern void DisposeTestClass( IntPtr pObject);
	}
}
